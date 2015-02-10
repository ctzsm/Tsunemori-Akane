#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int C, n, m, h[25][1005], f[25][1005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &C);
	while (C--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &h[i][j]);
				f[i][j] = -0x3f3f3f3f;
			}
		f[1][1] = h[1][1];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				f[i + 1][j] = max(f[i + 1][j], f[i][j] + h[i + 1][j]);
				f[i][j + 1] = max(f[i][j + 1], f[i][j] + h[i][j + 1]);
				for (int k = 2; k * j <= m; ++k)
					f[i][k * j] = max(f[i][k * j], f[i][j] + h[i][k * j]);
			}
		printf("%d\n", f[n][m]);
	}
	return 0;
}