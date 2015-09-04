#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[10005];
vector<int> adj[10005];
int p[10005];
unsigned long long dfs(int u) {
	unsigned long long res = 5;
	vector<unsigned long long> h;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		h.push_back(dfs(v));
	}
	sort(h.begin(), h.end());
	unsigned long long combine = 0;
	for (int i = 0; i < h.size(); ++i) {
		combine = combine * 7 + h[i];
	}
	return res * 17 + combine * 13 + h.size();
}
unsigned long long f() {
	int u = 0, cnt = 1;
	for (int i = 0; s[i]; ++i) adj[i].clear();
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '1') {
			int v = cnt++;
			p[v] = u;
			adj[u].push_back(v);
			u = v;
		} else {
			u = p[u];
		}
	}
	return dfs(0);
}
bool solve() {
	gets(s);
	unsigned long long h1 = f();
	gets(s);
	unsigned long long h2 = f();
	return h1 == h2;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T); gets(s);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "Same" : "Different");
	return 0;
}
