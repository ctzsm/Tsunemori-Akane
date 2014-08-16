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

int n, k, d;
int a[1005][1005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d", &n, &k, &d);
	if (k >= n) {
		for (int i = 0; i < d; ++i) {
			for (int j = 1; j <= n; ++j) printf("%d ", j);
			printf("\n");
		}
		return 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		int x = i;
		for (int j = 0; j < d; ++j) {
			a[i][j] = x % k;
			x /= k;
		}
		if (x) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < n; ++j) printf("%d ", a[j][i] + 1);
		printf("\n");
	}
	return 0;
}