#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<long long, int> PLI;
const long long oo = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100005;
int n, m, ans[maxn], p[maxn];
bool visited[maxn];
vector<pair<int, int> > adj[maxn];
long long d[maxn];
void spfa() {
	memset(d, 0x3f, sizeof d);
	priority_queue<PLI, vector<PLI>, greater<PLI> > q;
	q.push(make_pair(0, 1)); d[1] = 0;
	while (!q.empty()) {
		PLI now = q.top(); q.pop();
		int u = now.second;
		if (visited[u]) continue;
		visited[u] = true;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
				q.push(make_pair(d[v], v));
			}
		}
	}
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	spfa();
	if (d[n] == oo) {
		puts("-1");
		return 0;
	}
	int cur = n, pcnt = 0;
	while (cur) {
		ans[pcnt++] = cur;
		cur = p[cur];
	}
	for (int i = pcnt - 1; i >= 0; --i)
		printf("%d ", ans[i]);
	return 0;
}
