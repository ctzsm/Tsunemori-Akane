#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned int C[55][55];
void getC() {
	for (int i = 0; i <= 50; ++i)
		for (int j = 0; j <= i; ++j)
			if (i == 0 || i == j) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1]; 
}
int l = 0;
struct matrix {
	unsigned int a[55][55];
	matrix operator * (const matrix& x) const {
		matrix res; memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < l; ++j)
				for (int k = 0; k < l; ++k)
					res.a[i][j] += a[i][k] * x.a[k][j];
		return res;
	}
	matrix pow(long long k) {
		matrix res, p;
		memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < l; ++i) res.a[i][i] = 1;
		memcpy(p.a, a, sizeof p.a);
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < l; ++j) printf("%d\t", a[i][j]);
			printf("\n");
		}
	}
};
unsigned int solve() {
	int K; long long N;
	scanf("%lld%d", &N, &K);
	matrix a, c;
	memset(a.a, 0, sizeof a.a);
	memset(c.a, 0, sizeof c.a);
	l = K + 2;
	for (int i = 0; i < l; ++i) a.a[0][i] = 1;
	c.a[0][0] = 1;
	for (int i = 1; i < l; ++i) c.a[i][0] = C[K][i - 1];
	for (int j = 1; j < l; ++j)
		for (int i = j; i < l; ++i)
			c.a[i][j] = C[K - j + 1][i - j];
	a = a * c.pow(N - 1);
	return a.a[0][0];
}
int main() {
	freopen("in", "r", stdin);
	getC();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %u\n", _, solve());
	return 0;
}
