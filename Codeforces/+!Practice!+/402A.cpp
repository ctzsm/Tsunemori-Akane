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

int k, a, b, v;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d", &k, &a, &b, &v);
	int nk = b / (k - 1);
	if (nk * k * v >= a) {
		printf("%d\n", (a - 1) / (k * v) + 1);
		return 0;
	}
	int ans = nk;
	a -= nk * k * v;
	b -= nk * (k - 1);
	if ((b + 1) * v >= a) {
		printf("%d\n", ans + 1);
		return 0;
	}
	a -= (b + 1) * v;
	ans += 1;
	printf("%d\n", ans + (a - 1) / v + 1);
	return 0;
}