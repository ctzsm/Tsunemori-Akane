#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, n, m;
int h[1005][1005], l[1005], r[1005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				char s[5]; scanf("%s", s);
				h[i][j] = s[0] == 'F' ? 1 : 0;
			}
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (h[i][j])
					h[i][j] += h[i - 1][j];
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				l[j] = j;
				int x = j - 1;
				while (x >= 0 && h[i][x] >= h[i][j]) {
					l[j] = l[x];
					x = l[x] - 1;
				}
			}
			for (int j = m - 1; j >= 0; --j) {
				r[j] = j;
				int x = j + 1;
				while (x < m && h[i][x] >= h[i][j]) {
					r[j] = r[x];
					x = r[x] + 1;
				}
			}
			for (int j = 0; j < m; ++j) ans = max(ans, (r[j] - l[j] + 1) * h[i][j]);
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}