#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
}p[2005];
int d[2005][2005];
int dis(pnt& a, pnt& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int solve() {
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i) p[i].scan();
	for (int i = 0; i < n; ++i) {
		for (int j = 0, k = 0; j < n; ++j) {
			if (i == j) continue;
			d[i][k ++] = dis(p[i], p[j]);
		}
		sort(d[i], d[i] + n - 1);
		int x = 0, cnt = 0;
		for (int j = 0; j < n - 1; ++j) {
			if (x == d[i][j]) cnt ++;
			else {
				ans += cnt * (cnt - 1) / 2;
				x = d[i][j], cnt = 1;
			}
		}
		ans += cnt * (cnt - 1) / 2;
	}
	return ans;
}
int main() {
	freopen("boomerang_constellations.txt", "r", stdin);
	freopen("boomerang_constellations.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %d\n", _, solve());
	return 0;
}
