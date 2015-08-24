#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 15005;
const int mod = 100000007;
int f[2][maxn];
inline int MOD(int x) {
	if (x < 0) x += mod;
	if (x >= mod) x -= mod;
	return x;
}
inline int rsum(int i, int l, int r) {
	int x = 0, y = f[i][r];
	if (l >= 0) x = f[i][l];
	return MOD(y - x);
}
int solve() {
	int N, K, S; scanf("%d%d%d", &N, &K, &S);
	int now = 0, pre = 1;
	for (int i = 0; i <= S; ++i) f[pre][i] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) f[now][j] = 0;
		for (int j = i + 1; j <= S; ++j)
			f[now][j] = MOD(f[now][j - 1] + rsum(pre, j - K - 1, j - 1));
		swap(now, pre);
	}
	return rsum(pre, S - 1, S);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
