#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double mul = 1e4;
struct pnt {
	double x, y;
	void scan() { scanf("%lf%lf", &x, &y); }
	pnt operator - (const pnt& b) {
		pnt res;
		res.x = x - b.x, res.y = y - b.y;
		return res;
	}
	pnt operator + (const pnt& b) {
		pnt res;
		res.x = x + b.x, res.y = y + b.y;
		return res;
	}
	pnt operator / (const double len) {
		pnt res;
		res.x = x / len, res.y = y / len;
		return res;
	}
	pnt operator * (const double len) {
		pnt res;
		res.x = x * len, res.y = y * len;
		return res;
	}
};
typedef pnt vec;
double dis(pnt a, pnt b) {
	return hypot(a.x - b.x, a.y - b.y);
}
double solve() {
	pnt a, b, c, d;
	a.scan(); b.scan();
	c.scan(); d.scan();
	vec ab = b - a, cd = d - c;
	double l = 0, r = mul;
	while (r - l > eps) {
		double m1 = (l + (r - l) / 3.0) / mul;
		double m2 = (l + 2.0 * (r - l) / 3.0) / mul;
		double x = dis(a + ab * m1, c + cd * m1);
		double y = dis(a + ab * m2, c + cd * m2);
		if (x < y) r = m2 * mul;
		else l = m1 * mul;
	}
	return dis(a + ab * (l / mul), c + cd * (l / mul));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
