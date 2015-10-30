#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int _, n, d[14][14], f[1 << 14];
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &d[i][j]);
	for (int i = 1; i < (1 << n); ++i) {
		f[i] = 0;
		for (int j = 0; j < n; ++j) if (i & (1 << j)) {
			for (int k = 0; k < n; ++k) if (i & (1 << k)) {
				f[i] += d[j][k];
			}
		}
	}
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = i & (i - 1); j; j = (j - 1) & i)
			f[i] = min(f[i], f[j] + f[i - j]);
	}
	return f[(1 << n) - 1];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (_ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
