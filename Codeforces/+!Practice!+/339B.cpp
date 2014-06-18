#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int n, m;
int main() {
	std::cin >> n >> m;
	int cur = 1;
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		int a; std::cin >> a;
		if (a >= cur) {
			ans += a - cur;
		} else {
			ans += n - cur + a;
		}
		cur = a;
	}
	std::cout << ans << std::endl;
	return 0;
}