#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> adj[2005];
int dfs(int u) {
	int res = 0;
	for (int i = 0; i < adj[u].size(); ++i)
		res = max(res, dfs(adj[u][i]));
	return res + 1;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int p; scanf("%d", &p);
		if (p == -1) p = 0;
		adj[p].push_back(i + 1);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, dfs(i));
	printf("%d\n", ans - 1);
	return 0;
}
