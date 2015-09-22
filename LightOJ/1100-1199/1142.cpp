#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
inline int MOD(int x) {
	if (x >= 10) x -= 10;
	return x;
}
struct matrix {
	int a[30][30];
	matrix operator + (const matrix& x) const {
		matrix res; memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				res.a[i][j] = MOD(a[i][j] + x.a[i][j]);
		return res;
	}
	matrix operator * (const matrix& x) const {
		matrix res; memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) 
					res.a[i][j] += a[i][k] * x.a[k][j];
				res.a[i][j] %= 10;
			}
		return res;
	}
	matrix pow(int k) {
		matrix res, p;
		memset(res.a, 0, sizeof res.a);
		memcpy(p.a, a, sizeof p.a);
		for (int i = 0; i < n; ++i) res.a[i][i] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) printf("%d", a[i][j]);
			printf("\n");
		}
	}
}I;
matrix solve(matrix x, int k) {
	if (k == 1) return x;
	matrix res = (I + x.pow(k / 2)) * solve(x, k / 2);
	if (k & 1) return res + x.pow(k);
	return res;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 0; i < 30; ++i) I.a[i][i] = 1;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &k);
		matrix o;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &o.a[i][j]);
		solve(o, k).print();
	}
	return 0;
}
