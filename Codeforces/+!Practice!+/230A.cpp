#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

struct dragon {
	int x, y;
	dragon(){}
	bool operator < (const dragon& d) const {
		if (x == d.x) return y > d.y;
		return x < d.x;
	}
}d[1005];
int s, n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin); 
#endif
	scanf("%d%d", &s, &n);
	for (int i = 0; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		d[i].x = x, d[i].y = y;
	}
	std::sort(d, d + n);
	for (int i = 0; i < n; ++i) {
		if (s <= d[i].x) {
			printf("NO\n");
			return 0;
		}
		s += d[i].y;
	}
	printf("YES\n");
	return 0;
}