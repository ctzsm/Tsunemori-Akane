#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[105], f[105][105];
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int l = 2; l <= n; ++l) {
		for (int i = 1, j = i + l - 1; j <= n; ++i, ++j) {
			f[i][j] = f[i + 1][j] + 1;
			for (int k = i + 1; k <= j; ++k) {
				if (a[i] == a[k])
					f[i][j] = min(f[i][j], f[i + 1][k - 1] + f[k][j]);
			}
		}
	}
	return f[1][n];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int i = 1; i <= 100; ++i) f[i][i] = 1;
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
