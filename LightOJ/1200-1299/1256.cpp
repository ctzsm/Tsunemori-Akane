#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, in[26], has[26], f[26], ans[1005], ansp = 0;
char s[1005][21];
bool used[1005];
vector<pair<int, int> > adj[26];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void dfs(int u, int idx) {
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first, idx = adj[u][i].second;
		if (used[idx]) continue;
		used[idx] = true;
		dfs(v, idx);
		ans[ansp++] = idx;
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		memset(in, 0, sizeof in);
		memset(has, false, sizeof has);
		memset(used, false, sizeof used);
		for (int i = 0; i < 26; ++i) adj[i].clear();
		for (int i = 0; i < 26; ++i) f[i] = i;
		for (int i = 0; i < n; ++i) scanf("%s", s[i]);
		int start = -1;
		for (int i = 0; i < n; ++i) {
			int l = strlen(s[i]);
			int u = s[i][0] - 'a', v = s[i][l - 1] - 'a';
			adj[u].push_back(make_pair(v, i));
			in[u] --, in[v] ++;
			has[u] = has[v] = true;
			start = u;
			int fu = find(u), fv = find(v);
			if (fu != fv)
				f[fu] = fv;
		}
		int cnt = 0, ok = true, p1 = 0, n1 = 0;
		for (int i = 0; i < 26; ++i) {
			if (!has[i]) continue;
			if (in[i] == -1) start = i, n1++;
			if (in[i] == 1) p1++;
			if (in[i] > 1 || in[i] < -1) ok = false;
			if (find(i) == i) cnt ++;
		}
		if (cnt > 1) ok = false;
		if (n1 != p1) ok = false;
		if (n1 > 1) ok = false;
		printf("Case %d: ", _);
		if (!ok) {
			puts("No"); continue;
		} else puts("Yes");
		ansp = 0;
		dfs(start, -1);
		for (int i = n - 1; i >= 0; --i)
			printf("%s%c", s[ans[i]], i == 0 ? '\n' : ' ');
	}
	return 0;
}
