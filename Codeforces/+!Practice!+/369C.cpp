#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, ans = 0;
vector<pair<int, int> > adj[maxn];
bool choose[maxn];
bool dfs(int u, int p) {
	bool res = false;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first, need = adj[u][i].second == 2;
		if (v == p) continue;
		bool covered = dfs(v, u);
		if (!covered && need) {
			ans ++;
			choose[v] = true;
			res = true;
		}
		if (covered) res = true;
	}
	return res;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y, t; scanf("%d%d%d", &x, &y, &t);
		adj[x].push_back(make_pair(y, t));
		adj[y].push_back(make_pair(x, t));
	}
	dfs(1, 0);
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		if (choose[i]) printf("%d ", i);
	printf("\n");
	return 0;
}
