#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int t[1 << 18][3];
char f[1 << 18];
void build(int l, int r, int rt) {
	t[rt][0] = 1;
	t[rt][1] = t[rt][2] = f[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	t[rt][0] = t[rt << 1][0] + t[rt << 1 | 1][0];
}
inline void add(char& x, char y) {
	x += y;
	if (x >= 3) x -= 3;
}
inline void swapr(int rt) {
	swap(t[rt][0], t[rt][2]);
	swap(t[rt][1], t[rt][2]);
}
inline void swapl(int rt) {
	swap(t[rt][0], t[rt][2]);
	swap(t[rt][0], t[rt][1]);
}
inline void pushDown(int rt) {
	if (f[rt]) {
		if (f[rt] == 1) {
			swapr(rt << 1);
			swapr(rt << 1 | 1);
		}
		if (f[rt] == 2) {
			swapl(rt << 1);
			swapl(rt << 1 | 1);
		}
		add(f[rt << 1], f[rt]);
		add(f[rt << 1 | 1], f[rt]);
		f[rt] = 0;
	}
}
inline void pushUp(int rt) {
	for (int i = 0; i < 3; ++i)
		t[rt][i] = t[rt << 1][i] + t[rt << 1 | 1][i];
}
void update(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) {
		swapr(rt);
		add(f[rt], 1);
		return;
	}
	pushDown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, rt << 1, L, R);
	if (mid < R) update(mid + 1, r, rt << 1 | 1, L, R);
	pushUp(rt);
}
int query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R)
		return t[rt][0];
	pushDown(rt);
	int mid = (l + r) >> 1, res = 0;
	if (L <= mid) res += query(l, mid, rt << 1, L, R);
	if (mid < R) res += query(mid + 1, r, rt << 1 | 1, L, R);
	pushUp(rt);
	return res;
}
void solve() {
	int n, q; scanf("%d%d", &n, &q);
	build(0, n - 1, 1);
	while (q--) {
		int c, i, j; scanf("%d%d%d", &c, &i, &j);
		if (c) {
			printf("%d\n", query(0, n - 1, 1, i, j));
		} else {
			update(0, n - 1, 1, i, j);
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
