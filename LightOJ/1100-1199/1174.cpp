#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a[105][105], s, d;
int solve() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof a);
	for (int i = 0; i < n; ++i)
		a[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	scanf("%d%d", &s, &d);
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
	int res = 0;
	for (int i = 0; i < n; ++i)
		res = max(res, a[s][i] + a[i][d]);
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
