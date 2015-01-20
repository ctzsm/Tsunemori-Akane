#include <cstdio>
#include <algorithm>

using namespace std;

int L, N, C, T;
int VR, VT1, VT2, p[105];
double dp[105];
char yes[] = "Good job,rabbit!";
char no[] = "What a pity rabbit!";
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d", &L)) {
		scanf("%d%d%d", &N, &C, &T);
		scanf("%d%d%d", &VR, &VT1, &VT2);
		for (int i = 1; i <= N; ++i) scanf("%d", &p[i]); 
		p[0] = 0, p[N + 1] = L, dp[0] = 0.0;
		for (int i = 1; i <= N + 1; ++i) dp[i] = 1e200;
		for (int i = 0; i <= N + 1; ++i) {
			for (int j = i + 1; j <= N + 1; ++j) {
				int len = p[j] - p[i];
				double t = 0.0, t2 = len / VT2;
				if (len > C) t = 1.0 * C / VT1 + 1.0 * (len - C) / VT2;
				else t = 1.0 * len / VT1;
				if (i == 0) {
					dp[j] = min(dp[j], dp[i] + t);
				} else {
					dp[j] = min(dp[j], dp[i] + t + T);
				}
			}
		}
		printf("%s\n", (dp[N + 1] > (1.0 * L / VR)) ? yes : no);
	}
	return 0;
}