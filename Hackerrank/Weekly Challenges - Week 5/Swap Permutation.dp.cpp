#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const long long mod = 1e9 + 7;
int n, k;
long long dp[2505][2505];
void task1() {
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1;
		long long sum = dp[i-1][0];
		// dp[i][j] = sum{dp[i-1][j-k] 0 <= k <= min(i-1, j)}
		for (int j = 1; j <= k; ++j) {
			sum += dp[i-1][j];
			if (j >= i) sum -= dp[i-1][j-i];
			dp[i][j] = sum % mod;
		}
	}
	long long ans = 0;
	for (int i = k; i >= 0; i -= 2) ans += dp[n][i];
	printf("%lld ", ans % mod);
}
void task2() {
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i-1][j] + (i - 1) * dp[i-1][j-1] % mod;
			if (dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= k; ++i) ans += dp[n][i];
	printf("%lld\n", ans % mod);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d", &n, &k);
	task1();
	task2();
	return 0;
}