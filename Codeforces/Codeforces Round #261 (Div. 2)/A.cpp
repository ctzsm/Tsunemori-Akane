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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	bool flag = true;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 == x2) {
		int len = abs(y1 - y2);
		if (x1 - len >= -1000) {
			x3 = x4 = x1 - len;
			y3 = y1, y4 = y2;
		} else if (x1 + len <= 1000) {
			x3 = x4 = x1 + len;
			y3 = y1, y4 = y2;
		} else flag = false;
	} else if (y1 == y2) {
		int len = abs(x1 - x2);
		if (y1 - len >= -1000) {
			y3 = y4 = y1 - len;
			x3 = x1, x4 = x2;
		} else if (y1 + len <= 1000) {
			y3 = y4 = y1 + len;
			x3 = x1, x4 = x2;
		} else flag = false;
	} else {
		if (abs(y1 - y2) != abs(x1 - x2)) flag = false;
		else {
			x3 = x1, y3 = y2;
			x4 = x2, y4 = y1;
		}
	}
	if (flag)
		printf("%d %d %d %d\n", x3, y3, x4, y4);
	else
		printf("-1\n");
	return 0;
}