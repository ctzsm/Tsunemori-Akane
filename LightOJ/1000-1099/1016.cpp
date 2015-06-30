#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
	bool operator < (const pnt& p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
}p[50005];
int T, n, w;
int solve() {
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++i) p[i].scan();
	sort(p, p + n);
	int ans = 1, now = p[0].y;
	for (int i = 1; i < n; ++i) {
		if (p[i].y > now + w) {
			ans ++;
			now = p[i].y;
		}
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _  = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
