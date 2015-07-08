#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, m, a[2][505][505];
int f[505][505];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &m);
		for (int k = 0; k < 2; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					scanf("%d", &a[k][i][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 2; j <= m; ++j)
				a[0][i][j] += a[0][i][j - 1];
		for (int j = 1; j <= m; ++j)
			for (int i = 2; i <= n; ++i)
				a[1][i][j] += a[1][i - 1][j];
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				f[i][j] = max(f[i - 1][j] + a[0][i][j], f[i][j - 1] + a[1][i][j]);
		printf("Case %d: %d\n", _, f[n][m]);
	}
	return 0;
}
