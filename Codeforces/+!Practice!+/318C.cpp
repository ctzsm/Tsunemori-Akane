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

long long x, y, m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	std::cin >> x >> y >> m;
	if (x >= m || y >= m) {
		printf("0\n");
		return 0;
	}
	if (x <= 0 && y <= 0) {
		printf("-1\n");
		return 0;
	}
	long long ans = 0;
	while (true) {
		if (x >= m || y >= m) {
			std::cout << ans << std::endl;
			return 0;
		}
		if (x < y) std::swap(x, y);
		if (y < 0) 
			ans += -y / x, y += -y / x * x;
		y += x, ans ++;
	}
	return 0;
}