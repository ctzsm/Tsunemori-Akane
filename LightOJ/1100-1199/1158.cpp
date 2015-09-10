#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int d, n, m, f[1 << 10][1001], fact[11] = {1};
char s[15];
int cnt[11];
int solve() {
	scanf("%s%d", s, &d);
	n = strlen(s);
	m = 1 << n;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i) {
		s[i] -= '0';
		cnt[s[i]] ++;
	}
	memset(f, 0, sizeof f); f[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < d; ++j) {
			if (!f[i][j]) continue;
			for (int k = 0; k < n; ++k) {
				if (i & (1 << k)) continue;
				f[i | (1 << k)][(j * 10 + s[k]) % d] += f[i][j];
			}
		}
	}
	int& res = f[m - 1][0];
	for (int i = 0; i < 10; ++i)
		res /= fact[cnt[i]];
	return res;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 11; ++i) fact[i] = fact[i - 1] * i;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
