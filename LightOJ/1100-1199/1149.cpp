#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[105];
int n, m, a[105], b[105], mat[205];
bool used[205];
bool crosspath(int u) {
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!used[v]) {
			used[v] = true;
			if (mat[v] == -1 || crosspath(mat[v])) {
				mat[v] = u;
				return true;
			}
		}
	}
	return false;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; ++i)
		adj[i].clear();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (b[i] % a[j] == 0)
				adj[i].push_back(m + j);
	int ans = 0;
	memset(mat, -1, sizeof mat);
	for (int i = 0; i < m; ++i) {
		if (crosspath(i))
			ans ++;
		memset(used, false, sizeof used);
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
