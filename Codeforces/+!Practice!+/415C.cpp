#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n, k;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	if (n == 1 && k == 0) {
		printf("1\n");
		return 0;
	}
	if (n < 2 || n / 2 > k) {
		printf("-1\n");
		return 0;
	}
	int ans = k - n / 2 + 1;
	printf("%d %d", ans, ans * 2);
	for (int i = 2; i < n; ++i) printf(" %d", i - 1 + ans * 2);
	return 0;
}