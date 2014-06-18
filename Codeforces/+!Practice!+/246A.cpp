#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	if (n < 3) {
		printf("-1\n");
		return 0;
	}
	printf("2 3 1");
	for (int i = 3; i < n; ++i) printf(" 1");
	return 0;
}