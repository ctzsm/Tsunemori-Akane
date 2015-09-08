#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 10000000;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int _u, int _v, int _c):u(_u), v(_v), cap(_c) {}
}es[40005];
int S, T, R;
int dis[205], cur[205];
vector<int> adj[205];
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
int N, D, a[105];
char t[105];
bool check(int x) {
	S = 0, T = 1, R = 0;
	int cnt = 0;
	for (int i = 0; i <= 2 * N; ++i)
		adj[i].clear();
	for (int i = 1; i <= N; ++i) {
		if (a[i] <= x)
			addEdge(S, i << 1, oo);
		if (D - a[i] <= x)
			addEdge(i << 1 | 1, T, oo);
		addEdge(i << 1, i << 1 | 1, t[i] == 'B' ? oo : 1);
	}
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			if (a[j] - a[i] <= x)
				addEdge(i << 1 | 1, j << 1, oo), cnt++;
	int flow = dinic();
	return flow >= 2;
}
int solve() {
	scanf("%d%d", &N, &D);
	for (int i = 1; i <= N; ++i) {
		do {
			t[i] = getchar();
			if (t[i]  == 'S' || t[i] == 'B')
				break;
		} while (true);
		scanf("-%d", &a[i]);
	}
	int l = 0, r = D;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
