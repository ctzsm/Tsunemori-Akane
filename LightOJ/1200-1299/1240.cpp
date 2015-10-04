#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define square(x) ((x) * (x))
const double eps = 1e-6;
struct pnt {
	double x, y, z;
	pnt() {}
	pnt(double x, double y, double z): x(x), y(y), z(z) {}
	void scan() { scanf("%lf%lf%lf", &x, &y, &z); }
	double dist(const pnt& p) { return sqrt(square(x - p.x) + square(y - p.y) + square(z - p.z)); }
}p[3];
pnt midpoint(const pnt& a, const pnt& b, double l) {
	double x = a.x + (b.x - a.x) * l / 3.0;
	double y = a.y + (b.y - a.y) * l / 3.0;
	double z = a.z + (b.z - a.z) * l / 3.0;
	return pnt(x, y, z);
}
double solve() {
	double res = 1e10;
	for (int i = 0; i < 3; ++i) p[i].scan();
	for (int i = 0; i < 50; ++i) {
		pnt mid1 = midpoint(p[0], p[1], 1);
		pnt mid2 = midpoint(p[0], p[1], 2);
		double d1 = p[2].dist(mid1), d2 = p[2].dist(mid2);
		res = min(res, min(d1, d2));
		if (d1 < d2)
			p[1] = mid2;
		else
			p[0] = mid1;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
