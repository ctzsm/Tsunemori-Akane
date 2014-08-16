#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

std::vector<std::pair<int, int> > e[300005];
std::vector<int> dp[300005];
int n, m;
int dfs(int u, int i) {
	if (dp[u][i] != -1) return dp[u][i];
	dp[u][i] = 1;
	if (i + 1 < (int)e[u].size()) dp[u][i] = dfs(u, i + 1);
	int v = e[u][i].second, w = e[u][i].first + 1;
	int x = std::lower_bound(e[v].begin(), e[v].end(), std::make_pair(w, 0)) - e[v].begin();
	if (x < (int)e[v].size() && e[v][x].first >= w)
		dp[u][i] = std::max(dp[u][i], dfs(v, x) + 1);
	return dp[u][i];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(std::make_pair(w, v));
		dp[u].push_back(-1);
	}
	for (int i = 1; i <= n; ++i) std::sort(e[i].begin(), e[i].end());
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < (int)e[i].size(); ++j)
			ans = std::max(ans, dfs(i, j));
	printf("%d\n", ans);
	return 0;
}