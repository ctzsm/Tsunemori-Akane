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

using namespace std;

const long long oo = 0x7ffffffffffffLL;
int n;
long long d[2005][2005], d2[2005][2005];
vector<int> adj[2005];
vector<pair<long long, pair<int, int> > > edges;
long long b[2005];
void dfs(int u, int p, long long now) {
	b[u] = now;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u, now + d[u][v]);
	}
}
int f[2005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%lld", &d[i][j]);
	for (int i = 1; i <= n; ++i) if (d[i][i] != 0) {
			printf("NO\n");
			return 0;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (d[i][j] != d[j][i] || d[i][j] <= 0) {
				printf("NO\n");
				return 0;
			}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			edges.push_back(make_pair(d[i][j], make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0, j = 0; i < edges.size() && j < n - 1; ++i) {
		pair<long long, pair<int, int> > e = edges[i];
		int u = e.second.first, v = e.second.second;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		f[fu] = fv;
		adj[u].push_back(v);
		adj[v].push_back(u);
		j ++;
	}
	// printf("%d\n", n);
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d: ", i);
	// 	for (int j = 0; j < (int)adj[i].size(); ++j)
	// 		printf("%d ", adj[i][j]);
	// 	printf("\n");
	// }
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) b[j] = oo;
		dfs(i, 0, 0);
		for (int j = 1; j <= n; ++j) {
			d2[i][j] = b[j];
			if (d[i][j] != d2[i][j]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}