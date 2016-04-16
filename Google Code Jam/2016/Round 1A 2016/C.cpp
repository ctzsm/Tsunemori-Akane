#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int f[1005], g[1005], t[1005], color[1005];
int n, len[1005], res[1005];
bool visited[1005];
void dfs(int k, int d) {
	if (visited[k]) return;
	visited[k] = true;
	if (g[f[k]]) {
		if (g[f[k]] == d - 1) {
			t[k] = 1;
			color[k] = k;
			res[k] = len[k] = 1;
			return;
		}
		t[k] = 2, color[k] = k;
		len[k] = d - g[f[k]] + 1;
		return;
	}
	g[k] = d;
	dfs(f[k], d + 1);
	g[k] = 0;
	t[k] = t[f[k]], color[k] = color[f[k]];
	len[k] = len[f[k]] + (t[k] == 1);
	if (t[k] == 1 && f[f[k]] == k)
		len[k] = 1, color[k] = k;
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", f + i + 1);
	int col = 0, ans = 0;
	memset(res, 0, sizeof res);
	memset(visited, false, sizeof visited);
	memset(g, 0, sizeof g);
	memset(t, 0, sizeof t);
	memset(len, 0, sizeof len);
	memset(color, 0, sizeof color);
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) continue;
		dfs(i, 1);
		int c = color[i];
		if (t[i] == 1) res[c] = max(res[c], len[i]);
		else ans = max(ans, len[i]);
	}
	int ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (f[f[i]] == i) {
			ans2 += res[i] + res[f[i]];
			res[i] = res[f[i]] = 0;
		}
	}
	ans = max(ans, ans2);
	printf("%d\n", ans);
}
int main() {
	//freopen("in", "r", stdin);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
