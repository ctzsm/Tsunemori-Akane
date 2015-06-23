#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T, m;
map<string, int> h;
vector<int> adj[10005];
int in[10005];
void solve() {
	h.clear();
	scanf("%d", &m);
	int n = 0;
	memset(in, 0, sizeof in);
	for (int i = 0; i < m; ++i) adj[i].clear();
	for (int i = 0; i < m; ++i) {
		string s, t; cin >> s >> t;
		if (h.find(s) == h.end()) h[s] = n++;
		if (h.find(t) == h.end()) h[t] = n++;
		adj[h[s]].push_back(h[t]);
		in[h[t]] ++;
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
		if (!in[i])
			q.push(i);
	int ans = 0;
	while (!q.empty()) {
		ans ++;
		int now = q.front(); q.pop();
		for (int i = 0; i < adj[now].size(); ++i) {
			int v = adj[now][i];
			in[v]--;
			if (!in[v])
				q.push(v);
		}
	}
	puts(ans == n ? "Yes" : "No");
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
