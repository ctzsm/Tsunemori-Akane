#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int y, k, n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d", &y, &k, &n);
	bool flag = true;
	for (int i = 1; i <= n / k; ++i) {
		if (i * k > y) {
			flag = false;
			printf("%d ", i * k - y);
		}
	}
	if (flag) {
		printf("-1\n");
	}
	return 0;
}