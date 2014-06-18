#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, k;
int a[55];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	if (k > n) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);
	printf("%d %d\n", a[n - k], a[n - k]);
	return 0;
}