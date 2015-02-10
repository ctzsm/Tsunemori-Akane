#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, N, M[105];
double P, p[105];
double f[10005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%d", &P, &N);
		for (int i = 1; i <= N; ++i) scanf("%d%lf", &M[i], &p[i]);
		int V = accumulate(M + 1, M + N + 1, 0);
		for (int i = 1; i <= V; ++i) f[i] = 0.0;
		f[0] = 1.0;
		for (int i = 1; i <= N; ++i) {
			for (int j = V; j >= M[i]; --j)
				f[j] = max(f[j], f[j - M[i]] * (1.0 - p[i]));
		}
		int ans = 0;
		for (int j = V; j >= 1; --j) {
			if (1.0 - f[j] < P) {
				ans = j;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}