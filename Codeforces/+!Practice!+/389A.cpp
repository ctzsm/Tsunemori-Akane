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
	int gcd = 0;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		gcd = std::__gcd(gcd, x);
	}
	printf("%d\n", gcd * n);
	return 0;
}