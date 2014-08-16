#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <ctime>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int C[1000005];
int n, a[1000005];
int c[1000005], l[1000005];
std::map<int, int> h;
int lowbit(int x) {
	return x & -x;
}
void add(int x, int v) {
	while (x < n) {
		C[x] += v;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ret = 0;
	while (x) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; --i) {
		h[a[i]] ++;
		c[i] = h[a[i]];
	}
	h.clear();
	for (int i = 0; i < n; ++i) {
		h[a[i]] ++;
		l[i] = h[a[i]];
	}
	long long ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		add(c[i + 1], 1);
		ans += sum(l[i] - 1);
	}
	std::cout << ans << std::endl;
	return 0;
}