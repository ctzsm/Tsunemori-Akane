#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		sum += a;
	}
	if (sum % n == 0) {
		printf("%d\n", n);
	} else {
		printf("%d\n", n - 1);
	}
	return 0;
}