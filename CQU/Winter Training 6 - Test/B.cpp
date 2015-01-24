#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M, S;
int R[25], H[25];
void dfs(int d, int n, int upperR, int upperH, int nS) {
	if (nS + 2 * n / upperR >= S) return;
	if (d == M - 1) {
		for (int i = max(1, (int)(sqrt(n / upperH) + 1e-6)); i < upperR && i * i <= n; ++i) {
			if (n % (i * i) != 0) continue;
			int j = n / i / i;
			if (j < upperH) {
				S = min(S, nS + 2 * i * j + (d == 0 ? i *i : 0));
			}
		}
		return;
	}
	if (n <= 0) return;
	for (int i = min(upperR - 1, (int)sqrt(n / (M - d)) + 1); i >= M - d; --i) {
		for (int j = min(upperH - 1, n / i / i); j >= M - d; --j) {
			dfs(d + 1, n - j * i * i, i, j, nS + 2 * i * j + (d == 0 ? i * i : 0));
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &N, &M)) {
		S = N * N;
		dfs(0, N, N, N, 0);
		if (S == N * N) printf("0\n");
		else printf("%d\n", S);
	}
	return 0;
}