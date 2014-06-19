#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	int ans = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		int h; scanf("%d", &h);
		ans += abs(h - cur) + 2;
		cur = h;
	}
	printf("%d\n", ans - 1);
	return 0;
}