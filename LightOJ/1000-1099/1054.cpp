#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 65537;
const long long mod = 1000000007;
int T;
long long n, m;
vector<bool> isNotPrime(maxn, false);
int prime[maxn], pcnt = 0;
void getPrime() {
	for (int i = 2; i < maxn; ++i) {
		if (!isNotPrime[i]) {
			prime[pcnt++] = i;
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
		}
	}
}
long long modPow(long long a, long long k) {
	long long res = 1, p = a % mod;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
long long sum(long long p, long long m) {
	return ((modPow(p, m + 1) - 1 + mod) % mod) * modPow(p - 1, mod - 2) % mod;
}
long long solve() {
	scanf("%lld%lld", &n, &m);
	int sn = (int)(sqrt(n) + 1.1);
	long long ans = 1;
	for (int i = 0; prime[i] < sn && i < pcnt; ++i) {
		int cnt = 0;
		while (n % prime[i] == 0) {
			n /= prime[i];
			cnt ++;
		}
		if (cnt > 0) {
			sn = (int)(sqrt(n) + 1.1);
			ans = ans * sum(prime[i], cnt * m) % mod;
		}
		if (n < 2) break;
	}
	if (n > 1) {
		ans = ans * sum(n, m) % mod;
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
