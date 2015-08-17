#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int l = 1429431;
int c[l + 1];
inline int lowbit(int x) { return x & -x; }
int sum(int x) {
	int res = 0;
	while (x) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}
void update(int x, int v) {
	while (x <= l) {
		c[x] += v;
		x += lowbit(x);
	}
}
int get(int x) {
	int a = 1, b = l;
	while (a < b) {
		int mid = (a + b) >> 1;
		if (sum(mid) >= x) b = mid;
		else a = mid + 1;
	}
	return a;
}
void init() {
	int c = l / 2;
	for (int i = 1; i < l; i += 2)
		update(i, 1);
	for (int i = 2; i < l; ++i) {
		int x = get(i);
		for (int j = c / x * x; j > 0; j -= x) {
			int y = get(j);
			update(y, -1);
			c --;
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		printf("Case %d: %d\n", _, get(n));
	}
 	return 0;
}
