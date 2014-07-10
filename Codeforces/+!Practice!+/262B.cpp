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

int n, k;
int a[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);
	int neg = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) break;
		neg ++;
	}
	for (int i = 0; i < std::min(k, neg); ++i)
		a[i] = -a[i];
	std::sort(a, a + n);
	for (int i = 0; i < k - neg; ++i)
		a[0] = -a[0];
	printf("%d\n", std::accumulate(a, a + n, 0));
	return 0;
}