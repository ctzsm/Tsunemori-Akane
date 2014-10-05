#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 100003;
int T;
long long inv[100003] = {1};
long long f[100003] = {1, 1};
long long N, K;
long long modPow(long long n, long long k) {
	long long res = 1, p = n;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
long long nn[50], mm[50];
long long lucas(long long n, long long m) {
	if (m > n) return 0;
	if (m == n || m == 0) return 1;
	long long res = 1;
	int p = 0;
	while (n) {
		nn[p] = n % mod;
		mm[p++] = m % mod;
		n /= mod, m /= mod;
	}
	for (int i = p - 1; i >= 0; --i) {
		if (mm[i] == 0 || mm[i] == nn[i]) continue;
		if (mm[i] > nn[i]) return 0;
		res = res * f[nn[i]] % mod * inv[nn[i] - mm[i]] % mod * inv[mm[i]] % mod;
	}
	return res;
}
void solve() {
	scanf("%lld%lld", &N, &K);	
	if (N < K) {
		printf("0\n");
		return;
	}
	if (N == 1 && K == 1) {
		printf("1\n");
		return;
	}
	long long ans = lucas(N - K - 1, K);
	// printf("%lld %lld, ans1 = %lld\n", N - K - 1, K, ans);
	if (K >= 1) {
		ans += lucas(N - K - 1, K - 1) * 2;
		ans %= mod;
	}
	if (K >= 2) {
		ans += lucas(N - K - 1, K - 2);
		ans %= mod;
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < mod; ++i) inv[i] = modPow(i, mod - 2);
	for (int i = 2; i < mod; ++i) inv[i] = inv[i] * inv[i - 1] % mod;
	for (int i = 2; i < mod; ++i) f[i] = i * f[i - 1] % mod;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}