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

int n, m;
int f[55];
int find(int x) {
	if (x == f[x]) return x;
	f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	f[fx] = fy;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 0; i < m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		merge(x, y);
	}
	int ans = n;
	for (int i = 1; i <= n; ++i) if (find(i) == i) ans --;
	std::cout << (1LL << ans) << std::endl;
	return 0;
}