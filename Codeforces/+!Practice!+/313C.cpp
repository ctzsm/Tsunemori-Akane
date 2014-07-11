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

int n, a[2000005];
int p[] = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	long long m = 0, x = n;
	while (x) {
		m++;
		x >>= 2;
	}
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n, std::greater<int>());
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		ans += a[i] * m;
		if (i + 1 == p[j])
			j++, m--;
	}
	std::cout << ans << std::endl;
	return 0;
}