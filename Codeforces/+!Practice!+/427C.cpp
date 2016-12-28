#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
const int maxn = 100005;
int n, m, w[maxn], o[maxn], p = 0;
vector<int> adj[maxn], radj[maxn];
bool visited[maxn];
void dfs1(int u) {
	if (visited[u])
		return;
	visited[u] = true;
	for (int i = 0; i < radj[u].size(); ++i) {
		dfs1(radj[u][i]);
	}
	o[p++] = u;
}
void dfs2(int u, long long& ans1, long long& ans2) {
	if (visited[u])
		return;
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); ++i)
		dfs2(adj[u][i], ans1, ans2);
	if (ans1 == w[u])
		ans2 ++;
	else if (ans1 > w[u])
		ans1 = w[u], ans2 = 1;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", w + i + 1);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		radj[y].push_back(x);
	}
	for (int i = 0; i < n; ++i)
		dfs1(i + 1);
	memset(visited, false, sizeof visited);
	long long ans1 = 0, ans2 = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (!visited[o[i]]) {
			long long a1 = mod, a2 = 0;
			dfs2(o[i], a1, a2);
			ans1 += a1, ans2 = ans2 * a2 % mod;
		}
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}
