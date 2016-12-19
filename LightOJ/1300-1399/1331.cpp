#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(int _) {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double A = a + b, B = b + c, C = a + c;
	double sa = acos((B * B + C * C - A * A) / (B * C * 2));
	double sb = acos((A * A + C * C - B * B) / (A * C * 2));
	double sc = acos((A * A + B * B - C * C) / (A * B * 2));
	double area = sin(sa) * B * C - sa * c * c - sb * a * a - sc * b * b;
	printf("Case %d: %.6f\n", _, area / 2);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		solve(_);
	return 0;
}
