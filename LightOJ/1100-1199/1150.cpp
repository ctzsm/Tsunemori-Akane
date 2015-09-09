#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int maxn = 110;
const int maxm = 10000;
const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int u, int v, int c): u(u), v(v), cap(c) {}
}es[maxm];
int S, T, R, N, n;
int dis[maxn], cur[maxn];
vector<int> adj[maxn];
vector<edge> f[maxn];
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
char b[26][26];
int idx[26][26];
bool visited[26][26];
bool check(int x, int g, int h) {
	N = g + h; S = N ++; T = N ++; R = 0;
	for (int i = 0; i < N; ++i)
		adj[i].clear();
	for (int i = 0; i < g; ++i)
		addEdge(S, i, 1);
	for (int i = 0; i < h; ++i)
		addEdge(i + g, T, 1);
	for (int i = 0; i < g; ++i) {
		for (int j = 0; j < f[i].size(); ++j) {
			edge& e = f[i][j];
			if (e.cap * 2 + 2 <= x)
				addEdge(i, idx[e.u][e.v] + g, 1);
		}
	}
	return dinic() == h;
}
void bfs(int i, int j) {
	int id = idx[i][j];
	f[id].clear();
	memset(visited, false, sizeof visited);
	queue<edge> q; q.push(edge(i, j, 0));
	visited[i][j] = true;
	while (!q.empty()) {
		edge e = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int ni = e.u + dx[i], nj = e.v + dy[i];
			if (ni < 0 || ni >= n || nj < 0 || nj >= n)
				continue;
			if (visited[ni][nj] || b[ni][nj] == '#')
				continue;
			if (b[ni][nj] == 'H')
				f[id].push_back(edge(ni, nj, e.cap + 1));
			visited[ni][nj] = true;
			q.push(edge(ni, nj, e.cap + 1));
		}
	}
}
void solve() {
	int g = 0, h = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", b[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (b[i][j] == 'G') {
				idx[i][j] = g++;
				bfs(i, j);
			} else if (b[i][j] == 'H') idx[i][j] = h++;
		}
	}
	int l = 0, r = n * n;
	if (!check(r, g, h)) {
		printf("Vuter Dol Kupokat\n");
		return;
	}
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid, g, h)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
