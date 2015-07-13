#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, c[3];
int f[20][3];
int solve() {
	scanf("%d", &n);
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			for (int j = 0; j < 3; ++j)
				scanf("%d", &f[i][j]);
			continue;
		}
		for (int j = 0; j < 3; ++j)
			scanf("%d", &c[j]);
		for (int j = 0; j < 3; ++j) {
			int a = (j + 2) % 3, b = (j + 1) % 3;
			f[i][j] = min(f[i - 1][a], f[i - 1][b]) + c[j];
		}
	}
	int ans = f[n - 1][0];
	return min(ans, min(f[n - 1][1], f[n - 1][2]));
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
