#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
struct mat {
	long long a[2][2];
	mat() { memset(a, 0, sizeof a); }
	mat operator * (const mat& x) {
		mat res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k)
					res.a[i][j] += a[i][k] * x.a[k][j] % mod;
				res.a[i][j] %= mod;
			}
		return res;
	}
	mat pow(int k) {
		mat res, p;
		res.a[0][0] = res.a[1][1] = 1;
		memcpy(p.a, a, sizeof a);
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				printf("%lld ", a[i][j]);
			printf("\n");
		}
	}
};
int T, N, X, M, Y, K;
void solve() {
	scanf("%d%d%d%d%d", &N, &X, &M, &Y, &K);
	mat c;
	c.a[0][1] = c.a[1][0] = c.a[1][1] = 1;
	mat nc = c.pow(N);
	mat mc = c.pow(M);
	long long n1 = nc.a[1][0], n2 = nc.a[1][1];
	long long m1 = mc.a[1][0], m2 = mc.a[1][1];
	if ((m1 * X - n1 * Y) % (m1 * n2 - m2 * n1) ||
		(m2 * X - n2 * Y) % (m2 * n1 - m1 * n2)) {
		printf("Impossible\n");
		return;
	}
	long long a0 = (m2 * X - n2 * Y) / (m2 * n1 - m1 * n2);
	long long b0 = (m1 * X - n1 * Y) / (m1 * n2 - m2 * n1);
	if (a0 < 0 || b0 < 0) {
		printf("Impossible\n");
		return;
	}
	mat kc = c.pow(K);
	long long k1 = kc.a[1][0], k2 = kc.a[1][1];
	printf("%lld\n", (k1 * a0 + k2 * b0) % mod);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
