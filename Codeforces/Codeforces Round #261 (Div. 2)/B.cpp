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

int n, b[200005];
std::set<int> h;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	std::sort(b, b + n);
	for (int i = 0; i < n; ++i) h.insert(b[i]);
	if (h.size() == 1) {
		std::cout << 0 << " " << 1LL * n * (n - 1) / 2 << std::endl;
		return 0;
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] == b[0]) c1++;
		if (b[i] == b[n - 1]) c2++;
	}
	std::cout << b[n - 1] - b[0] << " " << 1LL * c1 * c2 << std::endl;
	return 0;
}