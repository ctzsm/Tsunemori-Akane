#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long t[1 << 18], f[1 << 18];
int n, q;
void build(int l, int r, int rt) {
	t[rt] = f[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void pushDown(int rt) {
	if (f[rt]) {
		f[rt << 1] += f[rt];
		f[rt << 1 | 1] += f[rt];
		f[rt] = 0;
	}
}
void pushUp(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
	t[rt] += (mid - l + 1) * f[rt << 1];
	t[rt] += (r - mid) * f[rt << 1 | 1];
}
void update(int l, int r, int rt, int L, int R, int v) {
	if (L <= l && r <= R) {
		f[rt] += v;
		return;
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, rt << 1, L, R, v);
	if (mid < R) update(mid + 1, r, rt << 1 | 1, L, R, v);
	pushUp(rt, l, r);
}
long long query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) {
		return t[rt] + (r - l + 1) * f[rt];
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	long long res = 0;
	if (L <= mid) res += query(l, mid, rt << 1, L, R);
	if (mid < R) res += query(mid + 1, r, rt << 1 | 1, L, R);
	pushUp(rt, l, r);
	return res;
}
void solve() {
	scanf("%d%d", &n, &q);
	build(0, n - 1, 1);
	int c, x, y, v;
	while (q--) {
		scanf("%d%d%d", &c, &x, &y);
		if (c == 0) {
			scanf("%d", &v);
			update(0, n - 1, 1, x, y, v);
		} else {
			printf("%lld\n", query(0, n - 1, 1, x, y));
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
