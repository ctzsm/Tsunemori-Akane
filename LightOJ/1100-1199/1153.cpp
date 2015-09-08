#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int _u, int _v, int _c): u(_u), v(_v), cap(_c) {}
}es[10005];
int S, T, R;
vector<int> adj[105];
int dis[105], cur[105];
void addEdge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(u, v, c);
	adj[v].push_back(R);
	es[R++] = edge(v, u, c);
}
bool dinic_bfs() {
	memset(dis, 0x3f, sizeof dis); dis[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			edge& e = es[adj[u][i]];
			if (dis[e.v] < oo || e.cap <= 0) continue;
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
		if (dis[e.v] != dis[u] + 1 || e.cap <= 0) continue;
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
	R = 0;
	int n, c; scanf("%d%d%d%d", &n, &S, &T, &c);
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 0; i < c; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
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
