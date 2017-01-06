#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n;
vector<int> adj[maxn];
long long a[maxn], f[maxn][2];
void dfs(int u, int p) {
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		f[u][0] = max(f[u][0], f[v][0]);
		f[u][1] = max(f[u][1], f[v][1]);
	}
	long long x = a[u] - f[u][0] + f[u][1];
	f[u][x < 0] += abs(x);
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	dfs(1, 0);
	printf("%lld\n", f[1][0] + f[1][1]);
	return 0;
}
