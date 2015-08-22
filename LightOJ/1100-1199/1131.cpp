#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int ms = 6;
int mod;
struct Matrix {
	int a[ms][ms];
	Matrix () { memset(a, 0, sizeof a); }
	Matrix operator * (const Matrix& x) {
		Matrix res;
		for (int i = 0; i < ms; ++i)
			for (int j = 0; j < ms; ++j)
				for (int k = 0; k < ms; ++k)
					res.a[i][j] = (res.a[i][j] + a[i][k] * x.a[k][j]) % mod;
		return res;
	}
	Matrix pow(int k) {
		Matrix res, p;
		for (int i = 0; i < ms; ++i) res.a[i][i] = 1;
		memcpy(p.a, a, sizeof a);
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
};
void solve() {
	int a[2], b[2], c[2], q;
	int f[3], g[3], x;
	for (int i = 0; i < 2; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	scanf("%d%d%d", &f[0], &f[1], &f[2]);
	scanf("%d%d%d", &g[0], &g[1], &g[2]);
	scanf("%d%d", &mod, &q);
	while (q--) {
		scanf("%d", &x);
		if (x < 3) {
			printf("%d %d\n", f[x] % mod, g[x] % mod);
			continue;
		}
		Matrix C, X;
		C.a[0][1] = C.a[1][2] = C.a[3][4] = C.a[4][5] = 1;
		C.a[0][0] = a[0], C.a[1][0] = b[0], C.a[5][0] = c[0];
		C.a[2][3] = c[1], C.a[3][3] = a[1], C.a[4][3] = b[1];
		for (int i = 0; i < 3; ++i)
			X.a[0][i] = f[2 - i] % mod;
		for (int i = 0; i < 3; ++i)
			X.a[0][i + 3] = g[2 - i] % mod;
		X = X * C.pow(x - 2);
		printf("%d %d\n", X.a[0][0], X.a[0][3]);
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
