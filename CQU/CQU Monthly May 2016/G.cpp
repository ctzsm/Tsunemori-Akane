#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int n, f[100005], rk[100005];
set<int> s[100005];
int find(int x) {
	if (f[x] == x) return x;
	s[f[x]].erase(x);
	f[x] = find(f[x]);
	s[f[x]].insert(x);
	return f[x];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	if (rk[fx] >= rk[fy]) {
		rk[fx] += rk[fy];
		s[f[fy]].erase(fy);
		f[fy] = fx;
		s[fx].insert(fy);
	} else {
		rk[fy] += rk[fx];
		s[f[fx]].erase(fx);
		f[fx] = fy;
		s[fy].insert(fx);
	}
}
int g[100005], pg;
void gao(int a) {
	for (set<int>::iterator it = s[a].begin(); it != s[a].end(); ++it) {
		g[pg++] = *it;
		if (*it == a) continue;
		gao(*it);
	}
	s[a].clear();
}
char o[5];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			s[i].insert(i);
			f[i] = i;
			rk[i] = 1;
		}
		while (m--) {
			scanf("%s", o);
			if (o[0] == 'U') {
				int x, y; scanf("%d%d", &x, &y);
				merge(x, y);
			}
			if (o[0] == 'D') {
				int x; scanf("%d", &x);
				int fx = find(x);
				pg = 0;
				gao(fx);
				for (int i = 0; i < pg; ++i) {
					s[g[i]].insert(g[i]);
					f[g[i]] = g[i];
					rk[g[i]] = 1;
				}
			}
			if (o[0] == 'S') {
				int x; scanf("%d", &x);
				int fx = find(x);
				printf("%d\n", rk[fx]);
			}
			if (o[0] == 'F') {
				int x, y; scanf("%d%d", &x, &y);
				int fx = find(x), fy = find(y);
				puts(fx == fy ? "Yes" : "No");
			}
		}
	}
	return 0;
}
