#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>


int T, N, M, K;
char ans[30];
int C[21][21];
void getC() {
	for (int i = 1; i < 21; ++i)
		for (int j = 0; j <= i; ++j)
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}
int main() {
	getC();
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &M, &K); K++;
		int nn = N + M;
		for (int i = 0; i < nn; ++i) ans[i] = 'H';
		for (int i = 0; i < nn && M && N; ++i) {
			if (K > C[N + M - 1][M]) {
				ans[i] = 'V';
				K -= C[N + M - 1][M];
				M --;
				if (K == 0) break;
			} else {
				N --;
			}
		}
		ans[nn] = '\0';
		int j = nn - 1;
		while (M) {
			ans[j--] = 'V';
			M --;
		}
		printf("%s\n", ans);
	}
	return 0;
}