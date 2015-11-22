#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int a[maxn], l[maxn], r[maxn];
int main() {
	// freopen("in", "r", stdin);
	int n, ans = 1; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	l[0] = a[0], r[n - 1] = a[n - 1];
	for (int i = 1; i < n; ++i) l[i] = max(a[i], l[i - 1]);
	for (int i = n - 2; i >= 0; --i) r[i] = min(a[i], r[i + 1]);
	for (int i = 1; i < n; ++i) if (l[i - 1] <= r[i]) ans ++;
	printf("%d\n", ans);
	return 0;
}
