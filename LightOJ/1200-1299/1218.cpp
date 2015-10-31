#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[105], mat[205];
vector<int> adj[205];
bool used[205], c[205];
bool crosspath(int u) {
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (used[v]) continue;
		used[v] = true;
		if (mat[v] == -1 || crosspath(mat[v])) {
			mat[v] = u;
			return true;
		}
	}
	return false;
}
int hungary() {
	int match = 0;
	memset(mat, -1, sizeof mat);
	for (int i = 0; i < n; ++i) {
		if (c[i]) continue;
		memcpy(used, c, 2 * n * sizeof(bool));
		if (crosspath(i)) match ++;
	}
	return match;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		sort(a, a + n);
		n = unique(a, a + n) - a;
		for (int i = 0; i < n * 2; ++i)
			adj[i].clear();
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (a[j] % a[i] == 0) {
					adj[i].push_back(j + n);
					adj[j + n].push_back(i);
				}
		memset(c, false, sizeof c);
		int match = hungary();
		for (int i = n - 1; i > -1; --i) {
			c[i] = c[i + n] = true;
			int tmatch = hungary();
			if (tmatch < match) {
				match = tmatch;
			} else {
				c[i] = c[i + n] = false;
			}
		}
		printf("Case %d:", _);
		for (int i = 0; i < n; ++i) if (!c[i])
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}
