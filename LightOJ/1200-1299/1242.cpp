#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = 41000;
struct edge {
	int v, cap;
	edge() {}
	edge(int v, int c): v(v), cap(c) {}
}es[maxm];
vector<int> tree[maxn], adj[maxn];
int cur[maxn], dis[maxn];
int S, T, R, N;
inline void add_edge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(v, c);
	adj[v].push_back(R);
	es[R++] = edge(u, 0);
}
bool dinic_bfs() {
	memset(dis, 0x3f, sizeof dis); dis[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			edge& e = es[adj[u][i]];
			if (e.cap < 1 || dis[e.v] < oo) continue;
			dis[e.v] = dis[u] + 1;
			q.push(e.v);
		}
	}
	return dis[T] < oo;
}
bool dinic_dfs(int u, int maxflow) {
	if (u == T) return maxflow;
	for (int i = cur[u]; i < adj[u].size(); ++i) {
		cur[u] = i;
		edge& e = es[adj[u][i]];
		if (e.cap < 1 || dis[e.v] != dis[u] + 1) continue;
		int flow = dinic_dfs(e.v, min(e.cap, maxflow));
		if (flow) {
			e.cap -= flow;
			es[adj[u][i] ^ 1].cap += flow;
			return flow;
		}
	}
	return 0;
}
int dinic() {
	int res = 0, flow;
	while (dinic_bfs()) {
		memset(cur, 0, sizeof cur);
		while (flow = dinic_dfs(S, oo))
			res += flow;
	}
	return res;
}
int p[maxn], o[maxn], child[maxn];
int dfs(int u, int pa) {
	p[u] = pa, o[u] = 0, child[u] = 1;
	for (int i = 0; i < tree[u].size(); ++i) {
		int v = tree[u][i];
		if (v == pa) continue;
		o[u] ++;
		child[u] += dfs(v, u);
	}
	return child[u];
}
int f[105][105], n, m;
int dp(int i, int j) {
	if (o[i] < o[j] || child[i] < child[j]) return 0;
	if (f[i][j - n] != -1) return f[i][j - n];
	for (int k = 0; k < tree[i].size(); ++k) {
		int u = tree[i][k];
		if (u == p[i]) continue;
		for (int l = 0; l < tree[j].size(); ++l) {
			int v = tree[j][l];
			if (v == p[j]) continue;
			dp(u, v);
		}
	}
	S = 0; N = n + m; T = ++N; R = 0;
	for (int k = 0; k <= N; ++k) adj[k].clear();
	for (int k = 0; k < tree[i].size(); ++k) {
		int u = tree[i][k];
		if (u == p[i]) continue;
		for (int l = 0; l < tree[j].size(); ++l) {
			int v = tree[j][l];
			if (v == p[j]) continue;
			if (dp(u, v))
				add_edge(u, v, 1);
		}
	}
	for (int k = 0; k < tree[i].size(); ++k) {
		int u = tree[i][k];
		if (u == p[i]) continue;
		add_edge(S, u, 1);
	}
	for (int k = 0; k < tree[j].size(); ++k) {
		int u = tree[j][k];
		if (u == p[j]) continue;
		add_edge(u, T, 1);
	}
	return f[i][j - n] = dinic() == o[j];
}
bool solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		tree[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1, 0);

	scanf("%d", &m);
	for (int i = 1 + n; i <= m + n; ++i)
		tree[i].clear();
	for (int i = 1; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		u += n; v += n;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(n + 1, 0);

	memset(f, -1, sizeof f);
	return dp(1, n + 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "Yes" : "No");
	return 0;
}
