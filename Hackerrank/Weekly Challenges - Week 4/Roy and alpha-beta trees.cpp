#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const long long MOD = 1000000009;
int T, N;
long long alpha, beta;
long long a[155];
long long dp[155][155][2], dp2[155];
inline long long mod1(long long x) {
	return x % MOD;
}
inline long long mod(long long x) {
	return ((x % MOD) + MOD) % MOD;
}
void init() {
	dp2[0] = 1;
	for (int i = 1; i <= 150; ++i) {
		for (int j = 0; j < i; ++j)
			dp2[i] = mod1(dp2[i] + mod1(dp2[j] * dp2[i - 1 - j]));
	}
}
pair<long long, long long> dfs(int l, int r) {
	if (dp[l][r][0] != -1 && dp[l][r][1] != -1)
		return make_pair(dp[l][r][0], dp[l][r][1]);
	dp[l][r][0] = dp[l][r][1] = 0;
	pair<long long, long long> x;
	for (int i = l; i <= r; ++i) {
		if (i - 1 >= l) {
			x = dfs(l, i - 1);
			dp[l][r][0] = mod1(dp[l][r][0] + mod1(x.second * dp2[r - i]));
			dp[l][r][1] = mod1(dp[l][r][1] + mod1(x.first * dp2[r - i]));
		}
		if (i + 1 <= r) {
			x = dfs(i + 1, r);
			dp[l][r][0] = mod1(dp[l][r][0] + mod1(x.second * dp2[i - l]));
			dp[l][r][1] = mod1(dp[l][r][1] + mod1(x.first * dp2[i - l]));
		}
		dp[l][r][0] = mod1(dp[l][r][0] + mod1(mod1(a[i] * dp2[i - l]) *  dp2[r - i]));
	}
	return make_pair(dp[l][r][0], dp[l][r][1]);
}
void solve() {
	scanf("%d%lld%lld", &N, &alpha, &beta);
	for (int i = 0; i < N; ++i) scanf("%lld", &a[i]);
	sort(a, a + N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; ++i) dp[i][i][0] = a[i], dp[i][i][1] = 0;
	pair<long long, long long> x = dfs(0, N - 1);
	printf("%lld\n", mod(mod(x.first * alpha) - mod(x.second * beta)));
}
int main() {
	init();
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}