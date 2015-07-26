#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int base[] = {1, 10, 100, 1000, 10000};
int mod = 1;
struct matrix {
	int a[2][2];
	matrix operator * (const matrix& x) {
		matrix res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				res.a[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					res.a[i][j] += a[i][k] * x.a[k][j];
				res.a[i][j] %= mod;
			}
		return res;
	}
	matrix pow(int k) {
		matrix res, p;
		memset(res.a, 0, sizeof res.a);
		memcpy(p.a, a, sizeof p.a);
		res.a[0][0] = res.a[1][1] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
};
int a, b, n, m;
void solve() {
	scanf("%d%d%d%d", &a, &b, &n, &m);
	mod = base[m];
	a %= mod, b %= mod;
	if (n == 0) {
		printf("%d\n", a);
		return;
	}
	if (n == 1) {
		printf("%d\n", b);
		return;
	}
	matrix x, co;
	memset(x.a, 0, sizeof x.a);
	memset(co.a, 0, sizeof co.a);
	x.a[0][0] = b, x.a[0][1] = a;
	co.a[0][0] = co.a[0][1] = co.a[1][0] = 1;
	x = x * co.pow(n - 1);
	printf("%d\n", x.a[0][0]);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
