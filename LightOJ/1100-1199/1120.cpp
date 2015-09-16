#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, PII> PIX;
int n, c[1 << 17], f[1 << 17];
int y[1 << 16], yc, ec;
PIX edge[1 << 16];
void build(int l, int r, int rt) {
	c[rt] = f[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void pushUp(int rt, int l, int r) {
	if (f[rt]) c[rt] = y[r + 1] - y[l];
	else if (l == r) c[rt] = 0;
	else c[rt] = c[rt << 1] + c[rt << 1 | 1];
}
void update(int l, int r, int L, int R, int v, int rt) {
	if (L <= l && r <= R) {
		f[rt] += v;
		pushUp(rt, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, L, R, v, rt << 1);
	if (mid < R) update(mid + 1, r, L, R, v, rt << 1 | 1);
	pushUp(rt, l, r);
}
inline int query() { return c[1]; }
long long solve() {
	int n; scanf("%d", &n);
	yc = ec = 0;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		edge[ec++] = make_pair(make_pair(x1, 1), make_pair(y1, y2));
		edge[ec++] = make_pair(make_pair(x2, -1), make_pair(y1, y2));
		y[yc++] = y1; y[yc++] = y2;
	}
	sort(edge, edge + ec);
	sort(y, y + yc);
	yc = unique(y, y + yc) - y;
	build(0, yc - 1, 1);
	long long ans = 0;
	for (int i = 0; i < ec - 1; ++i) {
		PIX& e = edge[i];
		int l = lower_bound(y, y + yc, e.second.first) - y;
		int r = lower_bound(y, y + yc, e.second.second) - y - 1;
		if (l <= r) update(0, yc - 1, l, r, e.first.second, 1);
		ans += 1LL * (edge[i + 1].first.first - e.first.first) * query();
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
