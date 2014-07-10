#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, m;
int v[1001], s[1001];
bool deleted[1001];
std::vector<int> adj[1001];
bool cmp(const int& x, const int& y) {
	return v[x] > v[y];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) s[i] = i;
	std::sort(s + 1, s + n + 1, cmp);
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int u: adj[s[i]]) {
			if (deleted[u]) continue;
			ans += v[u];
		}
		deleted[s[i]] = true;
	}
	std::cout << ans << std::endl;
	return 0;
}