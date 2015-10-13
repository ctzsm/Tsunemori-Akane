#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
long long f[1000005] = {1}, invf[1000005] = {1};
inline long long c(int n, int m) {
	return f[n] * invf[m] % mod * invf[n - m] % mod;
}
inline long long modPow(long long x, int k) {
	long long res = 1, p = x;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
long long solve() {
	int n; scanf("%d", &n);
	long long ans = 1, sum = 0;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		sum += x;
		ans = ans * c(sum - 1, x - 1) % mod;
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 1000001; ++i) f[i] = f[i - 1] * i % mod;
	for (int i = 1; i < 1000001; ++i) invf[i] = modPow(f[i], mod - 2);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
