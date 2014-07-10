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

struct fruit {
	int a, b;
	void read() {
		scanf("%d%d", &a, &b);
	}
}fruits[3005];
int n, v;
int day[3005][2];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; ++i) fruits[i].read();
	for (int i = 0; i < n; ++i) {
		day[fruits[i].a][0] += fruits[i].b;
	}
	int ans = 0;
	for (int i = 1; i <= 3001; ++i) {
		if (day[i][0] + day[i][1] > v) {
			ans += v;
			day[i][1] -= v;
			if (day[i][1] >= 0) {
				day[i + 1][1] += day[i][0];
			} else {
				day[i + 1][1] += day[i][0] + day[i][1];
			}
		} else {
			ans += day[i][0] + day[i][1];
		}
	}
	printf("%d\n", ans);
	return 0;
}