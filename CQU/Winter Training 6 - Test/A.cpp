#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, M, N;
int f[15][15];
void init() {
	for (int i = 0; i <= 10; ++i) f[i][0] = f[0][i] = 1;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i == 1 || j == 1) f[i][j] = 1;
			else f[i][j] = f[i - j][j] + f[i][j - 1];
		}
		for (int j = i + 1; j <= 10; ++j)
			f[i][j] = f[i][i];
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &M, &N);
		printf("%d\n", f[M][N]);
	}
	return 0;
}