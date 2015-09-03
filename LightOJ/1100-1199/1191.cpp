#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long f[55][55][55];
void init() {
	for (int m = 1; m <= 50; ++m)
		for (int i = 1; i <= m; ++i) f[i][1][m] = 1;
	for (int l = 2; l <= 50; ++l) { // current bar
		for (int i = 1; i <= 50; ++i) { // tot width
			for (int m = 1; m <= 50; ++m) { // max width
				for (int k = 1; k <= m && k < i; ++k) { // cur width
					f[i][l][m] += f[i - k][l - 1][m];
				}
			}
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, k, m; scanf("%d%d%d", &n, &k, &m);
		printf("Case %d: %lld\n", _, f[n][k][m]);
	}
	return 0;
}
