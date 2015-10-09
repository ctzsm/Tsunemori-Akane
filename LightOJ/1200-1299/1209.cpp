#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 500 + 5;
const int maxm = 250 * 250 * 2 + 1000;
struct edge {
	int v, cap;
	edge() {}
	edge(int v, int c): v(v), cap(c) {}
}es[maxm];
int S, T, R, N;
int dis[maxn], cur[maxn];
vector<int> adj[maxn];
void addEdge(int u, int v, int c) {
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
typedef pair<int, pair<int, int> > PIII;
vector<PIII> M, F;
char s[6], t[6];
inline pair<bool, int> parse(char s[]) {
	bool m = s[0] == 'M';
	int r = 0;
	for (int i = 1; s[i]; ++i)
		r = r * 10 + s[i] - '0';
	return make_pair(m, r);
}
int solve() {
	int m, f, v; scanf("%d%d%d", &m, &f, &v);
	N = v; S = N++; T = N++; R = 0;
	M.clear(); F.clear();
	for (int i = 0; i < N; ++i) adj[i].clear();
	for (int i = 0; i < v; ++i) {
		scanf("%s%s", s, t);
		pair<bool, int> v1 = parse(s), v2 = parse(t);
		if (v1.first) {
			M.push_back(make_pair(i, make_pair(v1.second, v2.second)));
			addEdge(S, i, 1);
		} else {
			F.push_back(make_pair(i, make_pair(v1.second, v2.second)));
			addEdge(i, T, 1);
		}
	}
	for (int i = 0; i < M.size(); ++i) {
		for (int j = 0; j < F.size(); ++j) {
			if (M[i].second.first == F[j].second.second ||
				M[i].second.second == F[j].second.first)
				addEdge(M[i].first, F[j].first, 1);
		}
	}
	return v - dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
