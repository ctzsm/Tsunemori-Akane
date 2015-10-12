#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
long long c[205][55], g[205][55], p[205][55];
void init() {
	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < min(51, i + 1); ++j)
			if (j == i || j == 0)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	for (int j = 0; j < 51; ++j)
		for (int i = 0; i < 201; ++i)
			if (i == 0) p[i][j] = 1;
			else p[i][j] = p[i - 1][j] * j % mod;
	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < 51; ++j) {
			g[i][j] = p[i][j];
			for (int k = 0; k < j; ++k) {
				g[i][j] -= g[i][k] * c[j][k] % mod;
				if (g[i][j] < 0) g[i][j] += mod;
			}
		}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int M, N, K; scanf("%d%d%d", &M, &N, &K);
		M ++, N ++;
		int e = M * N / 2, o = M * N / 2;
		if ((M * N) & 1) e ++;
		long long ans = 0;
		for (int k = 0; k <= K; ++k) {
			for (int i = 0; i <= k; ++i) {
				long long et = c[K][i] * g[e][i] % mod;
				long long ot = c[K - i][k - i] * g[o][k - i] % mod;
				ans = (ans + et * ot) % mod;
			}
		}
		printf("Case %d: %lld\n", _, ans);
	}
	return 0;
}
