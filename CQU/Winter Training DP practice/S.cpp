#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m, h[3][1005][1005], l[1005], r[1005];
char board[1005][1005];
int f[4][4] = {
	{2, 0, 1, 0},
	{2, 1, 2, 0},
	{2, 0, 2, 0},
	{3, 0, 1, 2}
};
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; ++i) scanf("%s", board[i]);
		memset(h, 0, sizeof h);
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) {
				char c = board[i][j];
				if (c <= 'c') h[c - 'a'][i][j] ++;
				else {
					int id = c - 'w';
					int ct = f[id][0];
					for (int k = 1; k <= ct; ++k) h[f[id][k]][i][j] ++;
				}
			}
		for (int k = 0; k < 3; ++k) 
			for (int i = 1; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (h[k][i][j])
						h[k][i][j] += h[k][i - 1][j];
		int ans = 0;
		for (int k = 0; k < 3; ++k)
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					l[j] = j;
					int x = j - 1;
					while (x >= 0 && h[k][i][x] >= h[k][i][j]) {
						l[j] = l[x];
						x = l[x] - 1;
					}
				}
				for (int j = m - 1; j >= 0; --j) {
					r[j] = j;
					int x = j + 1;
					while (x < m && h[k][i][x] >= h[k][i][j]) {
						r[j] = r[x];
						x = r[x] + 1;
					}
				}
				for (int j = 0; j < m; ++j) ans = max(ans, (r[j] - l[j] + 1) * h[k][i][j]);
			}
		printf("%d\n", ans);
	}
	return 0;
}