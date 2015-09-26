#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long n, K, MOD;
long long modPow(long long x, long long k, long long mod) {
	long long res = 1, p = x;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
int solve() {
	scanf("%lld%lld%lld", &n, &K, &MOD);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		ans += x;
		if (ans >= MOD) ans -= MOD;
	}
	return ans * modPow(n, K - 1, MOD) % MOD * K % MOD;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
