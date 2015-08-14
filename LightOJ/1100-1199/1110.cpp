#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105], t[105], ans[105];
int f[105][105][2]; // second dim 1 for up, 2 for left, 3 for diagonal.
string g[105][105];
int n, m;
void solve() {
	scanf("%s%s", s, t);
	n = strlen(s); reverse(s, s + n);
	m = strlen(t); reverse(t, t + m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1]) {
				f[i][j][0] = f[i - 1][j - 1][0] + 1;
				f[i][j][1] = 3;
				g[i][j] = s[i - 1] + g[i - 1][j - 1];
			} else {
				int d = 0;
				if (f[i - 1][j][0] == f[i][j - 1][0]) {
					d = g[i - 1][j] < g[i][j - 1] ? 1 : 2;
				} else {
					d = f[i - 1][j][0] > f[i][j - 1][0] ? 1 : 2;
				}
				if (d == 2) {
					f[i][j][0] = f[i][j - 1][0];
					g[i][j] = g[i][j - 1];
				} else {
					f[i][j][0] = f[i - 1][j][0];
					g[i][j] = g[i - 1][j];
				}
				f[i][j][1] = d;
			}
		}
	}
	int i = n, j = m, k = 0;
	while (i && j) {
		if (f[i][j][1] == 3) {
			ans[k++] = s[i - 1];
			i--, j--;
		} else if (f[i][j][1] == 2) {
			j--;
		} else {
			i--;
		}
	}
	ans[k] = 0;
	if (k)
		printf("%s\n", ans);
	else
		printf(":(\n");
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
