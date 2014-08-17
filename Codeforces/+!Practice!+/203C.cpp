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

int n, d, a, b;
std::pair<int, int> p[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d", &n, &d, &a, &b);
	for (int i = 0; i < n; ++i) {
		int l, h; scanf("%d%d", &l, &h);
		p[i] = std::make_pair(l * a + h * b, i + 1);
	}
	std::sort(p, p + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (d >= p[i].first) {
			ans ++;
			d -= p[i].first;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; ++i) printf("%d ", p[i].second);
	return 0;
}