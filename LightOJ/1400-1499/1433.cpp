#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
}o, a, b;
double dis(pnt& a, pnt& b) {
	return hypot(a.x - b.x, a.y - b.y);
}
double solve() {
	o.scan();
	a.scan();
	b.scan();
	double r = dis(a, o), ab = dis(a, b);
	double aob = acos(1.0 - ab * ab / (2.0 * r * r));
	return aob * r;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.6f\n", _, solve());
	return 0;
}
