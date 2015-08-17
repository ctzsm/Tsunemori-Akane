#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int m, n, d[10];
int f[10][11];
int dfs(int x, int s) {
	if (s == 1)
		return 1;
	if (f[x][s] != -1)
		return f[x][s];
	int res = 0;
	for (int i = 0; i < m; ++i) {
		if (abs(x - d[i]) <= 2)
			res += dfs(d[i], s - 1);
	}
	return f[x][s] = res;
}
int solve() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		scanf("%d", &d[i]);
	memset(f, -1, sizeof f);
	int ans = 0;
	for (int i = 0; i < m; ++i)
		ans += dfs(d[i], n);
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
