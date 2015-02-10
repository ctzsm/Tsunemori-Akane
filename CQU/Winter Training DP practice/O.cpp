#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m, k, s, a[105], b[105];
int f[205][105];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d%d%d", &n, &m, &k, &s)) {
		int V = n * 2;
		for (int i = 0; i < k; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			V = max(V, a[i]);
		}
		memset(f, -1, sizeof f);
		f[0][0] = m;
		for (int i = 0; i < k; ++i) {
			for (int j = a[i]; j <= V; ++j) {
				for (int k = 1; k <= s; ++k) {
					f[j][k] = max(f[j][k], f[j - a[i]][k - 1] - b[i]);
				}
			}
		}
		int ans = -1;
		for (int i = n; i <= V; ++i)
			for (int j = 0; j <= s; ++j) {
				ans = max(ans, f[i][j]);
			}
		printf("%d\n", ans);
	}
	return 0;
}