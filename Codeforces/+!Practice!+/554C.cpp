#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int mod_pow(long long x, long long k) {
	long long res = 1;
	while (k) {
		if (k & 1) res = res * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return res;
}
long long f[1005] = {1}, rf[1005];
inline long long C(int x, int y) {
	return f[x] * rf[y] % mod * rf[x - y] % mod;
}
int k, c[1005];
int main() {
	// freopen("in", "r", stdin);
	for (int i = 1; i <= 1000; ++i) f[i] = f[i - 1] * i % mod;
	rf[1000] = mod_pow(f[1000], mod - 2);
	for (int i = 999; i >= 0; --i) rf[i] = rf[i + 1] * (i + 1) % mod;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) scanf("%d", c + i);
	long long ans = 1, prefix = 0;
	for (int i = 0; i < k; ++i) {
		prefix += c[i];
		ans = ans * C(prefix - 1, c[i] - 1) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
