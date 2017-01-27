#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 4005;
int n, a[maxn], b[maxn], f[maxn][maxn];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
	sort(a, a + n);
	int m = unique(a, a + n) - a;
	for (int i = 0; i < n; ++i)
		b[i] = lower_bound(a, a + n, b[i]) - a + 1;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			f[i][b[j]] = max(f[i][b[j]], max(f[j][b[i]], 1) + 1);
			ans = max(ans, f[i][b[j]]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
