#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int maxn = 405;
const int maxm = 80005;
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
char b[22][22];
int solve() {
	int m, n, cnt = 0; scanf("%d%d", &m, &n);
	N = m * n; S = N ++; T = N ++; R = 0;
	for (int i = 0; i < N; ++i)
		adj[i].clear();
	for (int i = 0; i < m; ++i)
		scanf("%s", b[i]);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (b[i][j] == 'o') continue;
			cnt ++;
			if ((i + j) & 1) {
				addEdge(i * n + j, T, 1);
			} else {
				addEdge(S, i * n + j, 1);
				for (int k = 0; k < 4; ++k) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= m || nj < 0 || nj >= n)
						continue;
					if (b[i][j] == 'o') continue;
					addEdge(i * n + j, ni * n + nj, 1);
				}
			}
		}
	return cnt - dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
