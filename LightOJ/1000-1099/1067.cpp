#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const long long mod = 1000003;
long long f[1000005] = {1}, invf[1000005];
long long modPow(long long a, long long k) {
	long long res = 1, p = a % mod;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
long long inv(int k) {
	if (invf[k] == -1)
		invf[k] = modPow(f[k], mod - 2);
	return invf[k];
}
int T, n, k;
int solve() {
	scanf("%d%d", &n, &k);
	return f[n] * inv(k) % mod * inv(n - k) % mod;
}
int main() {
	freopen("in", "r", stdin);
	memset(invf, -1, sizeof invf);
	for (int i = 1; i < 1000001; ++i) f[i] = f[i - 1] * i % mod;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
