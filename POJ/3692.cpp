#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 2222;
const int maxm = 82222;
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
bool m[205][205];
void solve(int G, int B, int M, int cnt) {
	memset(m, false, sizeof m);
	for (int i = 0; i < M; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		m[x][y] = true;
	}
	int n = G + B + 1;
	S = n++; T = n++; R = 0;
	for (int i = 0; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= G; ++i) addEdge(S, i, 1);
	for (int i = 1; i <= B; ++i) addEdge(i + G, T, 1);
	for (int i = 1; i <= G; ++i) {
		for (int j = 1; j <= B; ++j)
			if (!m[i][j])
				addEdge(i, j + G, 1);
	}
	printf("Case %d: %d\n", cnt, G + B - dinic());
}
int main() {
	freopen("in", "r", stdin);
	int G, B, M, cnt = 1;
	while (true) {
		scanf("%d%d%d", &G, &B, &M);
		if (G == 0 && B == 0 && M == 0) break;
		solve(G, B, M, cnt++);
	}
	return 0;
}
