#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(int _) {
	int ax, ay, bx, by, cx, cy;
	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
	int dx = ax - bx + cx, dy = ay - by + cy;
	int cay = cy - ay, cax = cx - ax;
	int area = cax * cay - cax * (by - ay) - (cx - bx) * cay;
	printf("Case %d: %d %d %d\n", _, dx, dy, abs(area));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		solve(_);
	return 0;
}
