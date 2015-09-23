#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
ull f[55][55][2]; // 0 for up 1 for down
void init() {
	f[1][1][0] = f[1][1][1] = 1;
	for (int l = 2; l <= 50; ++l) {
		for (int i = 1; i <= l; ++i) {
			for (int j = 1; j < i; ++j) f[l][i][1] += f[l - 1][j][0];
			for (int j = i; j < l; ++j) f[l][i][0] += f[l - 1][j][1];
		}
	}
}
ull solve() {
	int N, m; scanf("%d%d", &N, &m);
	ull ans = 0;
	if (m == 1) {
		if (N < 3) return 1;
		return f[N - 1][2][1];
	}
	return f[N][m][1];
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %llu\n", _, solve());
	return 0;
}
