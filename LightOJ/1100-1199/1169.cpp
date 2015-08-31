#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[2][1005], t[2][1005];
int solve() {
	scanf("%d", &n);
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[j][i]);
	for (int j = 0; j < 2; ++j)
		for (int i = 1; i < n; ++i)
			scanf("%d", &t[j][i]);
	for (int i = 1; i < n; ++i) {
		a[0][i] += min(a[0][i - 1], a[1][i - 1] + t[1][i]);
		a[1][i] += min(a[1][i - 1], a[0][i - 1] + t[0][i]);
	}
	return min(a[0][n - 1], a[1][n - 1]);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: %d\n", _, solve());
	}
	return 0;
}
