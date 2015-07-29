#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, q, a[205];
int d[205][205], d2[205];
inline int cube(int x) {
	return x * x * x;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		scanf("%d", &m);
		memset(d, 0x3f, sizeof d);
		for (int i = 1; i <= n; ++i) d[i][i] = 0;
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			d[u][v] = cube(a[v] - a[u]);
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
		for (int i = 1; i <= n; ++i)
			d2[i] = d[1][i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d2[j] = min(d2[j], d2[i] + d[i][j]);
		for (int i = 1; i <= n; ++i)
			if (d2[i] < d[1][i])
				d[1][i] = -1;
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int u; scanf("%d", &u);
			if (d[1][u] < 3 || d[1][u] == 0x3f3f3f3f)
				printf("?\n");
			else
				printf("%d\n", d[1][u]);
		}
	}
	return 0;
}
