#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, string> g;
map<string, int> f;
int n, in[400];
vector<int> adj[400];
int main() {
	freopen("in", "r", stdin);
	int T; cin >> T;
	for (int _ = 1; _ <= T; ++_) {
		cout << "Case " << _ << ":" << endl;
		cin >> n;
		f.clear();
		g.clear();
		memset(in, 0, sizeof in);
		for (int i = 0; i < n; ++i) adj[i].clear();
		int c = 0;
		for (int i = 1; i < n; ++i) {
			string s, t; cin >> s >> t;
			if (f.find(s) == f.end()) {
				f[s] = c, g[c] = s;
				c ++;
			}
			if (f.find(t) == f.end()) {
				f[t] = c, g[c] = t;
				c ++;
			}
			adj[f[s]].push_back(f[t]);
			in[f[t]] ++;
		}
		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (!in[i])
				q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			printf("%s\n", g[u].c_str());
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				in[v] --;
				if (!in[v]) q.push(v);
			}
		}
		printf("\n");
	}
	return 0;
}
