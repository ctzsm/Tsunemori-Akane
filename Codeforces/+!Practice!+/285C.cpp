#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>

long long n, a[300005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; ++i)	{
		ans += abs(a[i] - (i + 1));
	}
	std::cout << ans << std::endl;
	return 0;
}