#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
vector<int> adj[10005];
int in[10005], m[10005];
int dfs(int u) {
	int res = m[u] - 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		int r = dfs(v);
		ans += abs(r);
		res += r;
	}
	return res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= n; ++i) in[i] = 0;
	for (int i = 1; i <= n; ++i) {
		int u, o, c; scanf("%d%d%d", &u, &o, &c);
		m[u] = o;
		for (int j = 0; j < c; ++j) {
			int v; scanf("%d", &v);
			in[v] ++;
			adj[u].push_back(v);
		}
	}
	int u = 0;
	for (int i = 1; i <= n; ++i) if (!in[i]) {
		u = i; break;
	}
	ans = 0;
	dfs(u);
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
