#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define xmul(x1, y1, x2, y2) ((x1)*(y2)-(x2)*(y1))
const double eps = 1e-8;
const double inf = 1e200;
struct pnt {
	double x, y;
	void scan() { scanf("%lf%lf", &x, &y); }
	pnt operator - (const pnt& p) const {
		pnt res; res.x = x - p.x, res.y = y - p.y;
		return res;
	}
}p[105], p1, p2 = {-inf, 0};
typedef pnt vec;
double nummul(const vec &v1, const vec &v2) { return v1.x * v2.x + v1.y * v2.y; }
double submul(const vec &v1, const vec &v2) { return xmul(v1.x, v1.y, v2.x, v2.y); }
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, q; scanf("%d", &n);
		for (int i = 0; i < n; ++i) p[i].scan();
		scanf("%d", &q);
		printf("Case %d:\n", _);
		while (q--) {
			p1.scan(); p2.y = p1.y;
			bool c = false;
			for (int i = 0, j = n - 1; i < n; j = i++) {
				if (fabs(submul(p[j] - p1, p[i] - p1)) < eps && nummul(p[j] - p1, p[i] - p1) < eps) { c = true; break; }
				if (fabs(p[j].y - p[i].y) < eps) continue;
				if (fabs(p[j].y - p1.y) < eps && p[j].x - p1.x < eps) { if (p[j].y - p[i].y < eps) c = !c; continue; }
				if (fabs(p[i].y - p1.y) < eps && p[i].x - p1.x < eps) { if (p[i].y - p[j].y < eps) c = !c; continue; }
				if (submul(p2 - p1, p[i] - p1) * submul(p2 - p1, p[j] - p1) < eps &&
					submul(p[j] - p[i], p1 - p[i]) * submul(p[j] - p[i], p2 - p[i]) < eps) c = !c;
			}
			puts(c ? "Yes" : "No");
		}
	}
	return 0;
}
