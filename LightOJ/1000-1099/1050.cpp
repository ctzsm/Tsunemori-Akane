#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, R, B;
double f[505][505];
double dfs(int r, int b) {
	if (r < 0 || b < 0) return 0.0;
	if (r >= b) return 0.0;
	if (f[r][b] >= 0.0) return f[r][b];
	double res = 0.0;
	res += 1.0 * r / (r + b) * dfs(r - 1, b - 1);
	res += 1.0 * b / (r + b) * dfs(r, b - 2);
	return f[r][b] = res;
}
double solve() {
	scanf("%d%d", &R, &B);
	return dfs(R, B);
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 0; i <= 500; ++i)
		for (int j = 0; j <= 500; ++j)
			f[i][j] = -1;
	f[0][1] = 1.0;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
