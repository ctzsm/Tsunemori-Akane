#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt {
	long long x, y;
}p[100005];
bool cmpx(const pnt& a, const pnt& b) { return a.x < b.x; }
struct cmpy {
	bool operator () (const pnt& a, const pnt& b) { return a.y < b.y; }
};
long long dist(int x, int y) {
	return 1ll * x * x + 1ll * y * y;
}
int n, a[100005];
int main() {
	// freopen("in", "r", stdin);
	while (~scanf("%d", &n)) {
		if (!n) break;
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			p[i].x = i + 1;
			p[i].y = sum += a[i];
		}
		long long d = dist(p[0].x - p[1].x, p[0].y - p[1].y);
		set<pnt, cmpy> s;
		for (int l = 0, i = 0; i < n; ++i) {
			while (l < i && p[i].x - p[l].x > d) s.erase(p[l++]);
			long long nd = (int)sqrt(d) + 1;
			pnt f = p[i]; f.y = f.y - nd;
			set<pnt, cmpy>::iterator it = s.lower_bound(f);
			while (it != s.end()) {
				if (it->y - p[i].y > nd) break;
				d = min(d, dist(p[i].x - it->x, p[i].y - it->y));
				it ++;
			}
			s.insert(p[i]);
		}
		printf("%lld\n", d);
	}
	return 0;
}
