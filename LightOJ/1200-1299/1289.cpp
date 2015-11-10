#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-2;
const int maxn = 100000000;
unsigned int check[maxn / 32 + 1];
unsigned int prime[maxn / 17], pcnt = 0;
unsigned int prefix[maxn / 17];
void getPrime() {
	for (int i = 2, fi = 0, si = 2; i <= maxn; ++i) {
		if (!(check[fi] & (1u << si))) prime[pcnt ++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			int tj = i * prime[j];
			int fj = tj >> 5, sj = tj & 0x1f;
			check[fj] |= 1u << sj;
			if (i % prime[j] == 0) break;
		}
		si ++;
		if (si == 32) {
			si = 0;
			fi ++;
		}
	}
	prefix[0] = prime[0];
	for (int i = 1; i < pcnt; ++i)
		prefix[i] = prefix[i - 1] * prime[i];
}
unsigned int mPow(unsigned int x, int k) {
	unsigned int res = 1, p = x;
	while (k) {
		if (k & 1) res *= p;
		p *= p;
		k >>= 1;
	}
	return res;
}
inline int calc(long long n, long long p) {
	int res = 0;
	while (n >= p) {
		n /= p;
		res ++;
	}
	return res;
}
unsigned int solve() {
	int n; scanf("%d", &n);
	int l = 0, r = pcnt - 1;
	if (n >= prime[pcnt - 1]) {
		l = pcnt - 1;
	} else {
		while (l < r) {
			int mid = (l + r) >> 1;
			if (prime[mid] > n) r = mid;
			else l = mid + 1;
		}
		l -= 1;
	}
	unsigned int ans = prefix[l];
	int sn = (int)(sqrt(n) + eps);
	for (int i = 0; prime[i] <= sn; ++i) {
		int cnt = calc(n, prime[i]);
		ans *= mPow(prime[i], cnt - 1);
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %u\n", _, solve());
	return 0;
}
