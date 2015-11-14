#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define xmul(x1, y1, x2, y2) ((x1)*(y2)-(x2)*(y1))

using namespace std;

const double eps = 1e-8;
const int maxn = 50005;
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
int n, d;
double solve() {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) p[i].scan();
	double ans = 2 * M_PI * d;
	if (n == 1) return ans;
	if (n == 2) return ans + 2 * (p[0] - p[1]).dis();
	n = graham(n, p, seq);
	for (int i = 0, j = n - 1; i < n; j = i++)
		ans += (p[seq[i]] - p[seq[j]]).dis();
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
