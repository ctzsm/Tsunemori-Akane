#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
struct Point {
	double x, y;
	bool operator < (const Point & a) const {
		if (y == a.y)
			return x < a.x;
		return y < a.y;
	}
	void scan() { scanf("%lf%lf", &x, &y); }
	void print() { printf("%f %f\n", x, y); }
};
int n, Stack[3005];
Point p[3005], q[3005];

int dblcmp(double d) {
	if (fabs(d) < EPS) return 0;
	return d < 0 ? -1 : 1;
}

double dis(Point& a, Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double det(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

double cross(Point& a, Point& b, Point& c) {
	return det(b.x - a.x, b.y - a.y, c.x - b.x, c.y - b.y);
}

int isleft(Point& a, Point& b, Point& c) {
	return dblcmp(cross(a, b, c));
}

int ConvexHull(int n) {
	int i;
	int top = -1;
	sort(p, p + n);
	Stack[++top] = 0;
	Stack[++top] = 1;
	for (i = 2; i < n; ++i) {
		while (top >= 1 && isleft(p[Stack[top - 1]], p[Stack[top]], p[i]) > 0) top--;
		Stack[++top] = i;
	}
	int temp_top = top;
	Stack[++top] = n - 2;
	for (i = n - 3; i >= 0; --i) {
		while (top >= temp_top + 1 && isleft(p[Stack[top - 1]], p[Stack[top]], p[i]) > 0) top--;
		Stack[++top] = i;
	}
	return top;
}
int ans[3005];
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) q[i].scan();
	for (int i = 0; i < n; ++i) ans[i] = max(n - 3, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) ;
	}
	for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
}
int main() {
	freopen("in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-small-attempt01.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		solve();
	}
	return 0;
}
