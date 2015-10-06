#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 10007;
const int maxn = 6;
struct matrix {
	int a[maxn][maxn];
	matrix operator * (const matrix& x) {
		matrix res; memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < maxn; ++i)
			for (int j = 0;j < maxn; ++j) {
				for (int k = 0; k < maxn; ++k)
					res.a[i][j] += a[i][k] * x.a[k][j];
				res.a[i][j] %= mod;
			}
		return res;
	}
	matrix pow(int k) {
		matrix res, p;
		memset(res.a, 0, sizeof res.a);
		memcpy(p.a, a, sizeof p.a);
		for (int i = 0; i < maxn; ++i) res.a[i][i] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < maxn; ++i) {
			for (int j = 0; j < maxn; ++j) printf("%d ", a[i][j]);
			printf("\n");
		}
	}
}a, o;
void init() {
	a.a[0][0] = 2;
	a.a[0][1] = a.a[0][2] = a.a[0][3] = 1;
	o.a[0][0] = o.a[1][0] = o.a[2][0] = o.a[3][0] = 1;
	o.a[3][1] = o.a[3][2] = 1;
	o.a[2][1] = o.a[1][2] = 1;
	for (int i = 0; i < 3; ++i) o.a[i][i + 3] = 1;
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		int ans = 1;
		if (n > 1) {
			matrix r = a * o.pow(n - 2);
			ans = r.a[0][0];
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
