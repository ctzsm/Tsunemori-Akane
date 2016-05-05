#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt {
	double x, y;
	void scan() { scanf("%lf%lf", &x, &y); }
}p[100005];
bool cmpx(const pnt& a, const pnt& b) { return a.x < b.x; }
bool cmpy(const int& a, const int& b) { return p[a].y < p[b].y; }
int n, idx[100005];
double dfs(int l, int r) {
	if (l >= r) return 1e100;
	if (l == r - 1) return hypot(p[l].x - p[r].x, p[l].y - p[r].y);
	int mid = (l + r) >> 1;
	double d = min(dfs(l, mid), dfs(mid + 1, r));
	int k = 0;
	for (int i = l; i <= r; ++i) {
		if (abs(p[i].y - p[mid].y) < d)
			idx[k++] = i;
	}
	sort(idx, idx + k, cmpy);
	for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j)
		d = min(d, hypot(p[idx[i]].x - p[idx[j]].x, p[idx[i]].y - p[idx[j]].y));
	return d;
}
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d", &n)) {
		if (!n) break;
		for (int i = 0; i < n; ++i) p[i].scan();
		sort(p, p + n, cmpx);
		printf("%.2f\n", dfs(0, n - 1) / 2.0);
	}
	return 0;
}
