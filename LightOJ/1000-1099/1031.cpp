#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;

int T, n, a[105], s[105], f[105][105];
int dfs(int i, int j) {
	if (i == j) return a[i];
	if (f[i][j] != oo) return f[i][j];
	int res = s[j] - s[i - 1];
	int sum = res;
	for (int k = i; k < j; ++k)
		res = max(res, sum - dfs(k + 1, j));
	for (int k = j; k > i; --k)
		res = max(res, sum - dfs(i, k - 1));
	return f[i][j] = res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	memset(f, 0x3f, sizeof f);
	return dfs(1, n) * 2 - s[n];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
