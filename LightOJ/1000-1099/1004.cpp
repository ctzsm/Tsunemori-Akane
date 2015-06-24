#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
int m[205][205];
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			scanf("%d", &m[i][j]);
	for (int i = n, k = n - 2; i < 2 * n - 1; ++i, --k)
		for (int j = 0; j <= k; ++j)
			scanf("%d", &m[i][j]);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= i; ++j) {
			int x = 0;
			if (j - 1 >= 0) x = max(x, m[i - 1][j - 1]);
			if (j <= i - 1) x = max(x, m[i - 1][j]);
			m[i][j] += x;
		}
	for (int i = n, k = n - 2; i < 2 * n - 1; ++i, --k)
		for (int j = 0; j <= k; ++j)
			m[i][j] += max(m[i - 1][j], m[i - 1][j + 1]);
	return m[2 * n - 2][0];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
