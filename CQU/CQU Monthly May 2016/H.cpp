#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 2238065148; // 2238065148 = 2 * 2 * 3 * 11 * 1459 * 11621
const long long mod2 = 16941960;
int mod_pow(long long x, long long k, long long m) {
	long long res = 1, p = x;
	while (k) {
		if (k & 1) res = res * p % m;
		p = p * p % m;
		k >>= 1;
	}
	return res;
}
void period() { // period of mod is mod2
	long long primes[5] = {2, 3, 11, 1459, 11621};
	long long res = 1;
	for (int i = 0; i < 5; ++i) {
		// find period of prime
		long long cnt = 1, a = 0, b = 1;
		for (int j = 0; ; ++j) {
			int c = (a + b) % primes[i];
			cnt ++;
			a = b;
			b = c;
			if (c == 0)
				break;
		}
		// ... a 0 ...
		// solve a^x = 1 (mod p)
		long long x = primes[i] - 1;
		for (int j = 1; j * j <= primes[i] - 1; ++j) {
			if ((primes[i] - 1) % j == 0) {
				if (mod_pow(a, j, primes[i]) == 1) {
					x = j; break;
				}
				if (mod_pow(a, (primes[i] - 1) / j, primes[i]) == 1) {
					x = min(x, (primes[i] - 1) / j);
				}
			}
		}
		// period = (length of a) * x
		cnt = cnt * x;
		// period of p^k = (period of p) * p^(k - 1)
		if (i == 0) cnt *= 2;
		// lcm
		res = res * cnt / __gcd(res, cnt);
	}
	printf("%lld\n", res);
}
template<long long mod>
class matrix {
public:
	long long a[2][2];
	matrix () { memset(a, 0, sizeof a); }
	matrix operator * (const matrix& rhs) const {
		matrix res;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					res.a[i][j] += a[i][k] * rhs.a[k][j] % mod;
					if (res.a[i][j] < 0)
						res.a[i][j] += mod;
					if (res.a[i][j] >= mod)
						res.a[i][j] -= mod;
				}
			}
		}
		return res;
	}
	matrix operator ^ (long long k) const {
		matrix res, p = *this;
		for (int i = 0; i < 2; ++i) res.a[i][i] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
};
long long getT(long long n) {
	if (n == 0) return 2;
	if (n == 1) return 3;
	matrix<mod2> tc, ta;
	tc.a[0][0] = 3, tc.a[0][1] = 2;
	ta.a[0][0] = 3, ta.a[0][1] = 1, ta.a[1][0] = -1;
	tc = tc * (ta ^ (n - 1));
	return tc.a[0][0];
}
long long getF(long long n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	matrix<mod> c, a;
	c.a[0][0] = 1;
	a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
	c = c * (a ^ (n - 1));
	return c.a[0][0];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		long long n; scanf("%lld", &n);
		printf("%lld\n", getF(getT(n)));
	}
	return 0;
}
