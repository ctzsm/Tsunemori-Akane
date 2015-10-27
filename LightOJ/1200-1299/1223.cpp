#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[101][101][101];
void init() {
	for (int i = 1; i <= 100; ++i) {
		for (int j = i; j <= 100; ++j)
			f[1][i][j] = (i + j) * (j - i + 1) / 2;
	}
	for (int k = 2; k <= 100; ++k)
		for (int i = 100; i > 0; --i)
			for (int j = i; j <= 100; ++j) {
				int& res = f[k][i][j];
				res = 0x3f3f3f3f;
				for (int l = i; l <= j; ++l)
					res = min(res, l + max(f[k - 1][i][l - 1], f[k][l + 1][j]));
			}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int k, m; scanf("%d%d", &k, &m);
		printf("Case %d: %d\n", _, f[k][1][m]);
	}
}
