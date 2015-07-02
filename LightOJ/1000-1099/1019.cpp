#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int oo = 0x3fffffff;
typedef pair<int, int> PII;

int T, n, m;
vector<PII> adj[105];
int d[105];
void Dijkstra() {
	for (int i = 1; i <= n; ++i) d[i] = oo;
	d[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(make_pair(d[1], 1));
	while (!q.empty()) {
		PII now = q.top(); q.pop();
		int u = now.second;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				q.push(make_pair(d[v], v));
			}
		}
	}
	if (d[n] == oo)
		printf("Impossible\n");
	else
		printf("%d\n", d[n]);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; ++i) adj[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		Dijkstra();
	}
	return 0;
}
