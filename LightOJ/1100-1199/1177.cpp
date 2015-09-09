#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110;
const int maxm = 4000;
const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int _u, int _v, int _c): u(_u), v(_v), cap(_c) {}
}es[maxm];
int S, T, N, R;
int dis[maxn], cur[maxn];
vector<int> adj[maxn];
void addEdge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(u, v, c);
	adj[v].push_back(R);
	es[R++] = edge(v, u, 0);
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
int dinic_dfs(int u, int maxflow) {
	if (u == T) return maxflow;
	for (int i = cur[u]; i < adj[u].size(); ++i) {
		cur[u] = i;
		edge& e = es[adj[u][i]];
		if (e.cap < 1 || dis[e.v] != dis[u] + 1) continue;
		int flow = dinic_dfs(e.v, min(maxflow, e.cap));
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
int solve() {
	int m, w; scanf("%d%d", &m, &w);
	S = 3, T = m << 1, R = 0;
	for (int i = 0; i < 2 * m + 2; ++i)
		adj[i].clear();
	for (int i = 2; i < m; ++i) {
		int c; scanf("%d", &c);
		addEdge(i << 1, i << 1 | 1, c);
	}
	for (int i = 0; i < w; ++i) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		addEdge(u << 1 | 1, v << 1, c);
		addEdge(v << 1 | 1, u << 1, c);
	}
	return dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
