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

int n, m, k;
int a[55];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1, std::greater<int>());
	int now = k;
	if (now >= m) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		now += a[i] - 1;
		if (now >= m) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}