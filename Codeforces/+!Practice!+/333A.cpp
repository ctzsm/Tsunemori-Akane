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
	while (n % 3 == 0) n /= 3;
	std::cout << (n - 1) / 3 + 1 << std::endl;
	return 0;
}