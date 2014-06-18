#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, d;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &d);
	int tot = 0, joke = 0;
	for (int i = 0; i < n; ++i) {
		int t; scanf("%d", &t);
		tot += t + 10;
		joke += 10;
	}
	tot -= 10, joke -= 10;
	if (d < tot) {
		printf("-1\n");
		return 0;
	}
	joke += d - tot;
	printf("%d\n", joke / 5);
	return 0;
}