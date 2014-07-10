#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int c1, c2, c3, c4;
int n, m;
int a[1005], b[1005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	int ans = c4;
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + m + 1);
	int amin = 0x3fffffff, bmin = 0x3fffffff;
	for (int i = 0; i <= n; ++i) {
		if (i > 0) a[i] += a[i - 1];
		amin = std::min(amin, a[i] * c1 + (n - i) * c2);
	}
	for (int i = 0; i <= m; ++i) {
		if (i > 0) b[i] += b[i - 1];
		bmin = std::min(bmin, b[i] * c1 + (m - i) * c2);
	}
	amin = std::min(amin, c3);
	bmin = std::min(bmin, c3);
	ans = std::min(ans, amin + bmin);
	printf("%d\n", ans);
	return 0;
}