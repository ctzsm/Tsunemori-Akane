#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000007;
char s[1005], t[1005];
int f[2][1005][2];
inline int MOD(int x) {
	if (x < 0) return x + mod;
	if (x >= mod) return x - mod;
	return x;
}
int solve() {
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	memset(f, 0, sizeof f);
	for (int i = 0; i < 2; ++i) f[i][0][1] = 1;
	for (int i = 0; i <= m; ++i) f[0][i][1] = 1;
	int pre = 1, now = 0;
	for (int i = 1; i <= n; ++i) {
		swap(pre, now);
		for (int j = 1; j <= m; ++j)
			f[now][j][1] = f[now][j][0] = 0;
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1]) {
				f[now][j][0] = f[pre][j - 1][0] + 1;
				f[now][j][1] = f[pre][j - 1][1];
			} else {
				f[now][j][0] = max(f[pre][j][0], f[now][j - 1][0]);
				if (f[now][j][0] == f[pre][j][0])
					f[now][j][1] += f[pre][j][1];
				if (f[now][j][0] == f[now][j - 1][0])
					f[now][j][1] += f[now][j - 1][1];
				f[now][j][1] = MOD(f[now][j][1]);
				if (f[now][j][0] == f[pre][j - 1][0])
					f[now][j][1] -= f[pre][j - 1][1];
				f[now][j][1] = MOD(f[now][j][1]);
			}
		}
	}
	return f[now][m][1];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
