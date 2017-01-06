#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, a[maxn], l[maxn], r[maxn];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	l[0] = r[n - 1] = 1;
	int ans = min(n, 2);
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1])
			l[i] = l[i - 1] + 1;
		else
			l[i] = 1;
		ans = max(ans, l[i] + (i + 1 < n));
	}
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] < a[i + 1])
			r[i] = r[i + 1] + 1;
		else
			r[i] = 1;
		ans = max(ans, r[i] + (i - 1 >= 0));
	}
	for (int i = 2; i < n; ++i) {
		if (a[i] - a[i - 2] > 1)
			ans = max(ans, l[i - 2] + r[i] + 1);
	}
	printf("%d\n", ans);
	return 0;
}
