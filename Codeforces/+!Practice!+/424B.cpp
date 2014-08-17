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

int n, s;
class pnt{
public:
	int x, y, k;
	void read() {
		scanf("%d%d%d", &x, &y, &k);
	}
	bool operator < (const pnt& b) const {
		return x * x + y * y < b.x * b.x + b.y * b.y;
	}
}p[1005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) p[i].read();
	std::sort(p, p + n);
	for (int i = 0; i < n; ++i) {
		s += p[i].k;
		if (s >= 1000000) {
			printf("%.10f\n", std::hypot(p[i].x, p[i].y));
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}