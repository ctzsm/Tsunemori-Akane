#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, q, f[45][45][45][45], g[45][45];
char board[45][45];
void gao(int x, int y) {
	for (int i = x; i <= n; ++i)
		g[i][y] = y - 1;
	for (int i = x; i <= n; ++i) {
		for (int j = y; j <= m; ++j) {
			f[x][y][i][j] = f[x][y][i - 1][j] + f[x][y][i][j - 1] - f[x][y][i - 1][j - 1];
			if (board[i][j] == '1') {
				g[i][j] = j;
			} else {
				if (j == y)
					g[i][j] = y - 1;
				else
					g[i][j] = g[i][j - 1];
				int l = y - 1;
				for (int k = i; k >= x; --k) {
					l = max(l, g[k][j]);
					f[x][y][i][j] += j - l;
				}
			}
		}
	}
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%s", board[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			gao(i, j);
	for (int i = 0; i < q; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", f[a][b][c][d]);
	}
	return 0;
}
