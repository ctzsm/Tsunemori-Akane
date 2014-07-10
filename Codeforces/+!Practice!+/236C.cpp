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

long long n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	std::cin >> n;
	if (n <= 2) {
		std::cout << n << std::endl;
		return 0;
	}
	if (n & 1)
		std::cout << n * (n - 1) * (n - 2) << std::endl;
	else 
		std::cout << std::max(n * (n - 1) * (n - 3) / std::__gcd(n, n - 3), (n - 1) * (n - 2) * (n - 3)) << std::endl;
	return 0;
}