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

int n, m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	if (!(n - 1 <= m && m <= (n + 1) * 2)) {
		printf("-1\n");
		return 0;
	}
	if (m > n * 2) {
		int x = m - n * 2;
		for (int i = 0; i < x; ++i) putchar('1');
		m -= x;
	}
	m -= n - 1;
	for (int i = 0; i < n; ++i) {
		putchar('0');
		if (i < n - 1) putchar('1');
		if (m) {
			putchar('1');
			m--;
		}
	}
	while (m--) 
		putchar('1');
	return 0;
}