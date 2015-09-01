#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;
const int maxm = 210001;
const int mod = 100000007;
const long long maxa = 10000000000LL;
long long prefect[111111], cnt = 0;
long long f[maxm] = {1};
void init() {
	for (int i = 2; ; ++i) {
		long long now = 1LL * i * i;
		if (now > maxa) break;
		while (now <= maxa) {
			prefect[cnt++] = now;
			now *= i;
		}
	}
	sort(prefect, prefect + cnt);
	cnt = unique(prefect, prefect + cnt) - prefect;
	for (int i = 1; i < maxm; ++i)
		f[i] = f[i - 1] * i % mod;
}
long long modPow(long long a, int k) {
	long long res = 1, p = a;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
int calc(long long x) {
	if (prefect[0] > x) return 0;
	if (prefect[cnt - 1] <= x) return cnt;
	return upper_bound(prefect, prefect + cnt, x) - prefect;
}
int solve() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	int tot = calc(b) - calc(a - 1);
	if (tot == 0) return 0;
	return f[tot * 2] * modPow(f[tot], mod - 2) % mod * modPow(f[tot + 1], mod - 2) % mod;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	init();
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
