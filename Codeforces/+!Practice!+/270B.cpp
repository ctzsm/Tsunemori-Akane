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
int C[100005], a[100005];
inline int lowbit(int x) {
	return x & -x;
}
void update(int x, int val) {
	while (x <= n) {
		C[x] += val;
		x += lowbit(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x > 0) {
		res += C[x];
		x -= lowbit(x);
	}
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	std::reverse(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		update(a[i], 1);
		if (sum(a[i] - 1) > 0) {
			printf("%d\n", n - i + 1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}