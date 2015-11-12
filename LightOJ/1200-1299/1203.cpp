#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define xmul(x1, y1, x2, y2) ((x1)*(y2)-(x2)*(y1))

using namespace std;

const double eps = 1e-8;
const int maxn = 100005;
struct pnt {
	double x, y;
	void scan() { scanf("%lf%lf", &x, &y); }
	pnt() {}
	pnt(double x, double y): x(x), y(y) {}
	bool operator < (const pnt& a) const {
		if (fabs(y - a.y) < eps) return x - a.x < -eps;
		return y - a.y < -eps;
	}
	pnt operator - (const pnt& a) const {
		return pnt(x - a.x, y - a.y);
	}
	double dis() {
		return hypot(x, y);
	}
}p[maxn];
typedef pnt vec;
inline double submul(const vec& v1, const vec& v2) { return xmul(v1.x, v1.y, v2.x, v2.y); }
int vercmp(const int& x, const int& y) { return p[x] < p[y]; }
int tmp[maxn], seq[maxn];
int graham(int n, pnt* p, int *seq) {
	int i, top, bot;
	for (int i = 0; i < n; ++i) tmp[i] = i;
	sort(tmp, tmp + n, vercmp);
	for (seq[top = bot = 0] = tmp[0], i = 1; i < n; ++i) {
		while (top > bot && submul(p[seq[top]] - p[seq[top - 1]], p[tmp[i]] - p[seq[top]]) < eps) --top;
		seq[++top] = tmp[i];
	}
	for (bot = top, i = n - 2; i >= 0; --i) {
		while (top > bot && submul(p[seq[top]] - p[seq[top - 1]], p[tmp[i]] - p[seq[top]]) < eps) --top;
		seq[++top] = tmp[i];
	}
	return top;
}
int n;
double solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) p[i].scan();
	if (n < 3) return 0.0;
	n = graham(n, p, seq);
	if (n < 3) return 0.0;
	double ans = 360;
	for (int i = 0, j = n - 1, k = n - 2; i < n; k = j, j = i++) {
		double a = (p[seq[i]] - p[seq[j]]).dis();
		double b = (p[seq[j]] - p[seq[k]]).dis();
		double c = (p[seq[i]] - p[seq[k]]).dis();
		double ang = acos((a * a + b * b - c * c) / 2.0 / a / b);
		ans = min(ans, ang / M_PI * 180);
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
