#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200005;
int n, q, a[maxn], b[maxn];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		b[l] ++, b[r + 1] --;
	}
	for (int i = 1; i <= n; ++i)
		b[i] += b[i - 1];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += 1ll * a[i] * b[i];
	printf("%lld\n", ans);
	return 0;
}
