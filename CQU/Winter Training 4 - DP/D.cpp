#include <bits/stdc++.h>

using namespace std;

int m;
char s[15];
int f[1005][11][11], p[1005][11][11];
int ff(int d, int w, int t) {
	if (f[d][w][t] != -1) return f[d][w][t];
	if (w >= t || w <= 0 || w >= 10) return f[d][w][t] = 0;
	int res = 0;
	for (int j = 1; j <= 10; ++j) {
		if (j != t && s[j] && ff(d - 1, t - w, j)) {
			p[d][w][t] = j;
			res = 1;
			break;
		}
	}
	return f[d][w][t] = res;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%s%d", s + 1, &m);
	memset(f, -1, sizeof f);
	memset(p, -1, sizeof p);
	for (int i = 1; i <= 10; ++i)
		f[1][i][i] = (s[i] -= '0');
	for (int i = 1; i <= 10; ++i) for (int j = 1; j <= 10; ++j)
		if (i != j) f[1][i][j] = 0;
	int ans = 0, id = 0, w = 0;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) 
			if (s[j] && ff(m, i, j)) {
				ans = 1, w = i, id = j;
				break;
			}
		if (ans) break;
	}
	printf(ans ? "YES\n" : "NO\n");
	vector<int> path;
	if (ans) {
		int i = m;
		while (id >= 1) {
			path.push_back(id);
			// printf("%d %d %d\n", i, w, id);
			int _w = abs(w - id);
			id = p[i--][w][id];
			w = _w;
		}
		reverse(path.begin(), path.end());
		for (int i = 0; i < path.size(); ++i)
			printf("%s%d", i ? " " : "", path[i]);
		printf("\n");
	}
	return 0;
}