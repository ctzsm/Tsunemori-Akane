#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const long long mod = 1000000007;
long long n;
std::vector<int> adj[100005];
bool visited[100005];
int dfs(int u) {
	if (visited[u]) return 0;
	visited[u] = true;
	int res = 1;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		res += dfs(adj[u][i]);
	}
	return res;
}
long long inv2 = 500000004, inv6 = 166666668;
int main() {
	freopen("in", "r", stdin);
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; char c[2];
		scanf("%d%d%s", &u, &v, c);
		// printf("%d %d %s\n", u, v, c);
		if (c[0] == 'b') {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	std::vector<int> g;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			int r = dfs(i);
			if (r > 1)
				g.push_back(r);
		}
	}
	long long ans = (n * (n - 1) % mod) * (n - 2) % mod * inv6 % mod;
	for (int i = 0; i < (int)g.size(); ++i) {
		if (g[i] >= 3) {
			long long t = g[i];
			ans -= t * (t - 1) % mod * (t - 2) % mod * inv6 % mod;
		}
		if (g[i] >= 2) {
			long long t = g[i];
			ans -= t * (t - 1) % mod * inv2 % mod * (n - t) % mod;
		}
	}
	ans = ((ans % mod) + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}