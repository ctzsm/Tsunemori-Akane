#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

double f[1005][1005], c2[2005];
void init() {
	for (int i = 1; i <= 2001; ++i) c2[i] = i * (i - 1) / 2.0;
	for (int i = 0; i <= 1000; ++i) f[0][i] = 1.0;
	for (int i = 2; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			int tot = i + j + 1;
			if (j == 0) {
				f[i][j] = f[i - 2][j] * c2[i] / c2[tot];
			} else {
				double p1 = (f[i - 2][j] * c2[i] + f[i][j - 1] * i * j) / (c2[tot] - j - c2[j]);
				double p2 = (f[i - 2][j] * c2[i] + f[i][j - 1] * (i + 1) * j) / (c2[tot] - c2[j]);
				f[i][j] = max(p1, p2);
			}
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int t, d; scanf("%d%d", &t, &d);
		printf("Case %d: %.10f\n", _, f[t][d]);
	}
	return 0;
}
