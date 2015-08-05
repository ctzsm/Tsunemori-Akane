#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x77777777;
typedef pair<int, int> PII;
int N, R;
int ds[5005], de[5005];
vector<PII> adj[5005];
bool visited[5005];
void Dijkstra(int s, int d[]) {
	memset(visited, false, sizeof visited);
	for (int i = 1; i <= N; ++i) d[i] = oo; d[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(make_pair(d[s], s)); visited[s] = true;
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (visited[v]) continue;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(make_pair(d[v], v));
			}
		}
	}
}
int solve() {
	scanf("%d%d", &N, &R);
	for (int i = 1; i <= N; ++i) adj[i].clear();
	for (int i = 0; i < R; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	Dijkstra(1, ds);
	Dijkstra(N, de);
	int res = oo, m = ds[N];
	for (int u = 1; u <= N; ++u)
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, w = adj[u][i].second;
			int l1 = ds[u] + w + de[v];
			int l2 = ds[u] + w * 3 + de[v];
			if (l1 > m) res = min(res, l1);
			if (l2 > m) res = min(res, l2);
		}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
