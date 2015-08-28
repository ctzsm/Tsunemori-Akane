#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[2][55][55];
char r[55], s[55], t[55];
int solve() {
	scanf("%s%s%s", r, s, t);
	int a = strlen(r);
	int b = strlen(s);
	int c = strlen(t);
	memset(f, 0, sizeof f);
	int now = 0, pre = 1;
	for (int i = 1; i <= a; ++i) {
		swap(now, pre);
		for (int j = 1; j <= b; ++j) {
			for (int k = 1; k <= c; ++k) {
				if (r[i - 1] == s[j - 1] && r[i - 1] == t[k - 1]) {
					f[now][j][k] = f[pre][j - 1][k - 1] + 1;
				} else {
					int x = 0;
					x = f[now][j][k - 1];
					x = max(x, f[now][j - 1][k]);
					x = max(x, f[now][j - 1][k - 1]);
					x = max(x, f[pre][j][k]);
					x = max(x, f[pre][j][k - 1]);
					x = max(x, f[pre][j - 1][k]);
					f[now][j][k] = x;
				}
			}
		}
	}
	return f[now][b][c];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
