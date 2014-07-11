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

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf ("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int k, a, m = 0; scanf("%d%d", &k, &a);
		for (m = 1; (1LL << (2 * m)) < a; ++m);
		ans = std::max(ans, k + m);
	}
	printf("%d\n", ans);
	return 0;
}