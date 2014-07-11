#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
long long ans = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		long long a; std::cin >> a;
		ans += i * (a - 1) + 1;
	}
	std::cout << ans << std::endl;
	return 0;
}