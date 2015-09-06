#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int N, S, T, R;
int dis[40005], cur[40005];
vector<int> adj[40005];
struct edge {
	int v, cap;
	edge() {}
	edge(int _v, int _c): v(_v), cap(_c) {}
}es[16 * 40005];
void addEdge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(v, c);
	adj[v].push_back(R);
	es[R++] = edge(u, 0);
}
bool dinic_bfs() {
	memset(dis, 0x3f, N * sizeof(int)); dis[S] = 0;
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
		memset(cur, 0, N * sizeof(int));
		while (flow = dinic_dfs(S, 1))
			res += flow;
	}
	return res;
}
bool board[40005];
int solve() {
	int m, n, k; scanf("%d%d%d", &m, &n, &k);
	N = n * m; S = N ++; T = N ++; R = 0;
	memset(board, false, N * sizeof(bool));
	for (int i = 0; i < k; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		x --, y --;
		board[x * n + y] = true;
	}
	for (int i = 0; i < N; ++i) adj[i].clear();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int u = i * n + j;
			if (board[u]) continue;
			if ((i + j) & 1) {
				addEdge(u, T, 1);
			} else {
				addEdge(S, u, 1);
				for (int l = 0; l < 8; ++l) {
					int ni = i + dx[l], nj = j + dy[l];
					if (ni < 0 || ni >= m || nj < 0 || nj >= n)
						continue;
					int v = ni * n + nj;
					if (board[v]) continue;
					addEdge(u, v, 1);
				}	
			}
		}
	}
	return n * m - k - dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
