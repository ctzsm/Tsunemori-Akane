#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char g[2][1005];
int d[2][1005];
int solve() {
	int n; scanf("%d", &n);
	scanf("%s%s", g[0], g[1]);
	memset(d, 0, sizeof d);
	for (int i = 0; i < 2; ++i) {
		int len = 0;
		for (int j = 0; j < n; ++j) {
			if (g[i][j] == 'X') {
				d[i][j] = 0;
				for (int k = 1; k <= len; ++k) d[i][j - k] = len;
				len = 0;
			} else len ++;
		}
		for (int k = 1; k <= len; ++k) d[i][n - k] = len;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (d[0][i] == 1 && d[1][i] == 1) {
			d[0][i] = d[1][i] = 0;
			ans ++;
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j) {
			if (d[i][j] == 1) {
				ans ++;
				if (d[i ^ 1][j] != -1) {
					int now = d[i ^ 1][j], k = j - 1;
					while (k >= 0 && d[i ^ 1][k] == now) d[i ^ 1][k--] = -1;
					k = j;
					while (k < n && d[i ^ 1][k] == now) d[i ^ 1][k++] = -1;
				}
			}
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j) {
			if (d[i][j] > 1) {
				ans ++;
				int now = d[i][j], k = j;
				while (k < n && d[i][k] == now) d[i][k++] = -1;
			}
		}
	return ans;
}
int main() {
	freopen("high_security.txt", "r", stdin);
	freopen("high_security.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %d\n", _, solve());
	return 0;
}
