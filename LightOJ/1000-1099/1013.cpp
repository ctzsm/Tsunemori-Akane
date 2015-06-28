#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, ans, n, m;
char s[35], t[35];
int f[35][35];
long long g[35][35][65];
int calc1() {
	n = strlen(s), m = strlen(t);
	memset(f, 0, sizeof f);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	return ans = n + m - f[n][m];
}
long long calc2(int i, int j, int l) {
	if (i == 0 || j == 0) {
		if (l == i + j) return 1;
		else return 0;
	}
	if (g[i][j][l] != -1) return g[i][j][l];
	if (s[i - 1] == t[j - 1])
		return g[i][j][l] = calc2(i - 1, j - 1, l - 1);
	return g[i][j][l] = calc2(i - 1, j, l - 1) + calc2(i, j - 1, l - 1);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%s%s", s, t);
		memset(g, -1, sizeof g);
		calc1();
		printf("Case %d: %d %lld\n", _, ans, calc2(n, m, ans));
	}
	return 0;
}
