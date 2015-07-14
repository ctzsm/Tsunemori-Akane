#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
int T, n;
vector<PII> adj[105];
bool visited[105];
int calc(vector<int>& seq) {
	int res = 0;
	for (int i = 0; i < seq.size() - 1; ++i) {
		int u = seq[i], v = seq[i + 1];
		for (int j = 0; j < adj[u].size(); ++j)
			if (adj[u][j].first == v)
				res += adj[u][j].second;
	}
	return res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 0; i < n; ++i) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		adj[x].push_back(make_pair(y, 0));
		adj[y].push_back(make_pair(x, w));
	}
	vector<int> seq;
	memset(visited, false, sizeof visited);
	for (int now = 1; ;) {
		seq.push_back(now);
		visited[now] = true;
		bool flag = false;
		for (int j = 0; j < adj[now].size(); ++j) {
			int v = adj[now][j].first;
			if (visited[v]) continue;
			flag = true;
			now = v;
			break;
		}
		if (!flag) break;
	}
	seq.push_back(seq[0]);
	int ans = calc(seq);
	reverse(seq.begin(), seq.end());
	return min(ans, calc(seq));
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
