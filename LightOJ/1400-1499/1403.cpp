#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 2222;
const int maxm = 22222;
struct edge {
	int v, cap;
	edge() {}
	edge(int v, int c): v(v), cap(c) {}
}es[maxm];
vector<int> adj[maxn];
int S, T, R, N;
int dis[maxn], cur[maxn];
int addEdge(int u, int v, int c) {
	es[R] = edge(v, c);
	adj[u].push_back(R++);
	es[R] = edge(u, 0);
	adj[v].push_back(R++);
}
int dinicDFS(int u, int maxflow) {
	if (u == T) return maxflow;
	for (int i = cur[u]; i < adj[u].size(); ++i) {
		cur[u] = i;
		edge& e = es[adj[u][i]];
		if (e.cap < 1 || dis[e.v] != dis[u] + 1) continue;
		int flow = dinicDFS(e.v, min(maxflow, e.cap));
		if (flow) {
			e.cap -= flow;
			es[adj[u][i] ^ 1].cap += flow;
			return flow;
		}
	}
	return 0;
}
bool dinicBFS() {
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
int dinic() {
	int res = 0, flow;
	while (dinicBFS()) {
		memset(cur, 0, sizeof cur);
		while (flow = dinicDFS(S, oo))
			res += flow;
	}
	return res;
}
int solve() {
	int n, m; scanf("%d%d", &n, &m);
	S = 0, T = 1, R = 0;
	for (int i = 0; i <= n * 2 + 1; ++i) adj[i].clear();
	for (int i = 1; i <= n; ++i) {
		addEdge(S, i << 1, 1);
		addEdge(i << 1 | 1, T, 1);
	}
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		addEdge(u << 1, v << 1 | 1, 1);
	}
	return n - dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
