#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
const int maxn = 2000001;

int n, k;
long long f[maxn] = {1};
long long modPow(long long a, int k) {
	long long res = 1, p = a;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < maxn; ++i) f[i] = f[i - 1] * i % mod;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &k);
		long long ans = f[n + k - 1] * modPow(f[k - 1], mod - 2) % mod;
		ans = ans * modPow(f[n], mod - 2) % mod;
		printf("Case %d: %lld\n", _, ans);
	}
	return 0;
}
