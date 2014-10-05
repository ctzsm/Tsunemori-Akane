#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct pnt{
	int x, y;
	double watan2(const int x, const int y) const {
		double t = atan2(y, x);
		if (t < 0.0) t += M_PI * 2.0;
		return t;
	}
	bool operator < (const pnt& p) const {
		if (x == 0 && y == 0) return true;
		if (watan2(x, y) == watan2(p.x, p.y)) 
			return x * x + y * y < p.x * p.x + p.y * p.y;
		return watan2(x, y) < watan2(p.x, p.y);
	}
}p[1005];
int N;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p, p + N);
	for (int i = 0; i < N; ++i)
		printf("%d %d\n", p[i].x, p[i].y);
	return 0;
}