#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 10007;
struct matrix {
	int a[4][4];
	matrix() { memset(a, 0, sizeof a); }
	matrix operator * (const matrix& x) {
		matrix res;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k) {
					res.a[i][j] += a[i][k] * x.a[k][j];
					res.a[i][j] %= mod;
				}
		return res;
	}
	matrix pow(int k) {
		matrix res, p;
		memcpy(p.a, a, sizeof a);
		for (int i = 0; i < 4; ++i) res.a[i][i] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
	void print() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) printf("%d ", a[i][j]);
			printf("\n");
		}
	}
};
int n, A[4];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d%d%d", &n, &A[0], &A[2], &A[3]);
		int ans = 0;
		if (n > 2) {
			matrix b, c;
			b.a[0][3] = 1;
			for (int i = 0; i < 4; ++i) c.a[i][0] = A[i];
			for (int i = 0; i < 2; ++i) c.a[i][i + 1] = 1;
			c.a[3][3] = 1;
			b = b * c.pow(n - 2);
			ans = b.a[0][0];
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
