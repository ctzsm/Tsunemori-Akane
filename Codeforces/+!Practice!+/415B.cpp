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

long long n, a, b;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld%lld", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		int l = 0, r = x, m;
		int y = (int)std::ceil((x * a / b) * 1.0 * b / a);
		printf("%d ", x - y);
	}
	return 0;
}