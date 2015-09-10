#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 360;
const int maxm = 2000;
const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int u, int v, int c): u(u), v(v), cap(c) {}
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
char s[2][6];
int convert(char s[]) {
	int l = strlen(s);
	if (l == 3) return 0;
	if (l == 2) {
		if (s[1] == 'L') return 1;
		return 5;
	}
	if (s[0] == 'L') return 2;
	if (s[0] == 'M') return 3;
	return 4;
}
bool solve() {
	int n, m; scanf("%d%d", &n, &m);
	N = n * 6 + m; S = N ++; T = N ++; R = 0;
	for (int i = 0; i < N; ++i)
		adj[i].clear();
	for (int i = 0; i < n * 6; ++i) {
		addEdge(S, i, 1);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%s%s", s[0], s[1]);
		for (int k = 0; k < 2; ++k) {
			int x = convert(s[k]);
			for (int j = x; j < n * 6; j += 6) {
				addEdge(j, n * 6 + i, 1);
			}
		}
		addEdge(n * 6 + i, T, 1);
	}
	return dinic() == m;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "YES" : "NO");
	return 0;
}
