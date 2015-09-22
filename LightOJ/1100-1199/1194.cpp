#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
long long dp[1 << 16], pre[16], cnt[16][16];
long long solve() {
	scanf("%d%d", &n, &m);
	memset(pre, 0, sizeof pre);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x); x--;
		for (int j = 0; j < m; ++j)
			cnt[x][j] += pre[j];
		pre[x] ++;
	}
	memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	int l = 1 << m;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) continue;
			long long c = 0;
			for (int k = 0; k < m; ++k) {
				if (k == j || (i & (1 << k))) continue;
				c += cnt[j][k];
			}
			dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + c);
		}
	}
	return dp[l - 1];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
