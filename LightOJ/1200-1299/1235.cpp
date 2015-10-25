#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m, K, a[3][18], f[2][20000], b[10] = {1};
bool calc(int n, int o, int f[]) {
	int m = b[n];
	for (int i = 1; i < m; ++i) {
		int mask = i, x = 0;
		for (int j = 0; j < n && mask; ++j) {
			x += a[mask % 3][j + o];
			mask /= 3;
		}
		f[i] = x;
		if (x == K) return true;
	}
	sort(f, f + m);
	return false;
}
bool solve() {
	scanf("%d%d", &n, &K); m = n >> 1;
	for (int i = 0; i < n; ++i) scanf("%d", a[1] + i);
	for (int i = 0; i < n; ++i) a[2][i] = a[1][i] + a[1][i];
	if (calc(m, 0, f[0])) return true;
	if (calc(n - m, m, f[1])) return true;
	for (int i = 0, j = b[n - m] - 1; i < b[m]; ++i) {
		while (j > 0 && f[0][i] + f[1][j] > K) j --;
		if (K == f[0][i] + f[1][j]) return true;
	}
	return false;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 10; ++i) b[i] = b[i - 1] * 3;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "Yes" : "No");
	return 0;
}
