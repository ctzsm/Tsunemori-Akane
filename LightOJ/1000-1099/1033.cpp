#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, f[105][105];
char s[105];
int dfs(int i, int j) {
	if (i > j) return 0;
	if (f[i][j] != -1) return f[i][j];
	if (i == j) return f[i][j] = 1;
	int res = 0;
	if (s[i] == s[j])
		res = max(res, dfs(i + 1, j - 1) + 2);
	else {
		res = max(res, dfs(i + 1, j));
		res = max(res, dfs(i, j - 1));
	}
	return f[i][j] = res;
}
int solve() {
	scanf("%s", s);
	n = strlen(s);
	memset(f, -1, sizeof f);
	return n - dfs(0, n - 1);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}