#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, K, q, m;
int f[1 << 12][12][12];
bool h[12][12];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d%d", &n, &K, &q);
		memset(f, 0, sizeof f);
		memset(h, false, sizeof h);
		for (int i = 0; i < n; ++i) {
			int p; scanf("%d", &p);
			for (int j = 0; j < p; ++j) {
				int t; scanf("%d", &t); t--;
				h[t][i] = true;
			}
		}
		for (int i = 0; i < n; ++i)
			f[1 << i][i][0] = 1;
		m = 1 << n;
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) { // end with j
				for (int k = 0; k < n - 1; ++k) {
					if (!f[i][j][k]) continue;
					for (int l = 0; l < n; ++l) {
						if ((i & (1 << l))) continue;
						if (h[j][l]) f[i | 1 << l][l][k + 1] += f[i][j][k];
						else f[i | 1 << l][l][k] += f[i][j][k];
					}
				}
			}
		}
		printf("Case %d:\n", _);
		while (q--) {
			int r, ans = 0; scanf("%d", &r);
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (j * K > r) break;
					ans += f[m - 1][i][j];
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}
