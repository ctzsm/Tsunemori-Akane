#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int m, n;
int q[100005], a[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x; scanf("%d", &x);
		q[x] = 1;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n, std::greater<int>());
	int cnt = n + 1, which = 0;
	for (int i = 1; i <= 100000; ++i) {
		if (q[i]) {
			int rr = n % (i + 2);
			int qq = n / (i + 2);
			int now = qq * i;
			if (rr > 2 && q[rr - 2]) {
				now += rr - 2;
			} else if (rr > 1 && q[rr - 1]) {
				now += rr - 1;
			} else {
				now += rr;
			}
			if (cnt > now) {
				cnt = now, which = i;
			}
		}
	}
	int ans = 0, rr = n % (which + 2), qq = n / (which + 2);
	int i = 0;
	for (; i < qq * (which + 2); ++i) {
		if (i % (which + 2) < which)
			ans += a[i];
	}
	if (rr > 2 && q[rr - 2]) n -= 2;
	else if (rr > 1 && q[rr - 1]) n -= 1;
	for (; i < n; ++i) {
		ans += a[i];
	}
	printf("%d\n", ans);
	return 0;
}