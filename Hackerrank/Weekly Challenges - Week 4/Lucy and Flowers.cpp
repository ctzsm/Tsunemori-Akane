#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const long long mod = 1000000009;
int T, N;
long long ans[5005], fi[5005], fi2[5005];
long long modPow(long long a, long long k, long long m) {
	long long p = a, res = 1;
	while (k) {
		if (k & 1) res = res * p % m;
		p = p * p % m;
		k >>= 1;
	}
	return res;
}
void calc() {
	long long fn = 1;
	for (int i = 1; i <= 5001; ++i) fi[i] = modPow(i, mod - 2, mod);
	for (int i = 1; i <= 5001; ++i) fi2[i] = fi[i] * fi[i] % mod;
	for (int n = 1; n <= 5000; ++n) {
		fn = fn * n % mod;
		long long tmp = 1, n1 = n;
		for (int i = 1; i <= n; ++i) {
			tmp = ((((tmp * ((i << 1) - 1) % mod) * (i << 1) % mod) * n1 % mod) * fi2[i] % mod) * fi[i + 1] % mod;
			n1--;
			ans[n] = (ans[n] + tmp) % mod;
		}
	}
}
int main() {
	calc();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", (int)ans[N]);
	}
	return 0;
}