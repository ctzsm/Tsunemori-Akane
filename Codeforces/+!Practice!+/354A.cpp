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

int n, l, r, Ql, Qr;
int w[100005], sl[100005], sr[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d%d", &n, &l, &r, &Ql, &Qr);
	for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i) sl[i] = sl[i - 1] + w[i];
	for (int i = n; i >= 1; --i) sr[i] = sr[i + 1] + w[i];
	int ans = 0x7fffffff;
	for (int i = 0; i <= n; ++i) {
		int tl = i, tr = n - i, e = 0;
		if (tl >= tr)
			e = std::max(tl - tr - 1, 0) * Ql;
		else
			e = std::max(tr - tl - 1, 0) * Qr;
		ans = std::min(ans, sl[i] * l + sr[i + 1] * r + e);
	}
	printf("%d\n", ans);
	return 0;
}