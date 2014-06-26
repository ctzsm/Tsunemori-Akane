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

int n;
int a[200005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int sum = std::accumulate(a + 1, a + n + 1, 0);
	long long ans1 = 0, ans2, zero = n - sum;
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			ans1 += zero;
		} else {
			zero --;
		}
	}
	int one = sum;
	for (int i = n ; i >= 1; --i) {
		if (!a[i]) {
			ans2 += zero + one;
		} else {
			zero --;
		}
	}
	std::cout << std::min(ans1, ans2) << std::endl;
	return 0;
}