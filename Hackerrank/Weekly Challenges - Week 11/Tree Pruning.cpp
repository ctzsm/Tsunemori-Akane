#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

const int maxn = 100005;
const long long inf = 0x3fffffffffffffffLL;
int N, K;
int s[maxn], d[maxn], cnt = 1;
std::vector<int> adj[maxn];
long long f[205][maxn], w[maxn];
void dfs(int u, int p) {
	s[u] = 1;
	d[cnt++] = u;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		s[u] += s[v];
	}
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%lld", &w[i]);
	for (int i = 2; i <= N; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	memset(f, 0x3f, sizeof f);
	for (int j = 0; j <= K; ++j) f[j][0] = 0;
	for (int i = 1; i <= N; ++i) f[0][i] = w[d[i]] + f[0][i - 1];
	for (int j = 1; j <= K; ++j) {
		for (int i = 1; i <= N; ++i) f[j][i] = -inf;
		for (int i = 1; i <= N; ++i)
			f[j][i + s[d[i]] - 1] = std::max(f[j][i + s[d[i]] - 1], f[j - 1][i - 1]);
		for (int i = 1; i <= N; ++i)
			f[j][i] = std::max(f[j][i], f[j][i - 1] + w[d[i]]);
	}
	printf("%lld\n", f[K][N]);
	return 0;
}