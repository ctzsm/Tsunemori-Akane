#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long t[1 << 18], f[1 << 18];
void print(long long x, long long y) {
	if (x % y == 0) {
		printf("%lld\n", x / y);
		return;
	}
	long long gcd = __gcd(x, y);
	printf("%lld/%lld\n", x / gcd, y / gcd);
}
void build(int l, int r, int rt) {
	t[rt] = 0; f[rt] = -1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void pushDown(int rt, int l, int r) {
	if (f[rt] != -1) {
		int mid = (l + r) >> 1;
		f[rt << 1] = f[rt << 1 | 1] = f[rt];
		t[rt << 1] = f[rt] * (mid - l + 1);
		t[rt << 1 | 1] = f[rt] * (r - mid);
		f[rt] = -1;
	}
}
void pushUp(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
	f[rt] = -1;
}
void update(int l, int r, int rt, int L, int R, int v) {
	if (L <= l && r <= R) {
		t[rt] = v * (r - l + 1), f[rt] = v;
		return;
	}
	pushDown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, rt << 1, L, R, v);
	if (mid < R) update(mid + 1, r, rt << 1 | 1, L, R, v);
	pushUp(rt, l, r);
}
long long query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R)
		return t[rt];
	pushDown(rt, l, r);
	long long res = 0;
	int mid = (l + r) >> 1;
	if (L <= mid) res += query(l, mid, rt << 1, L, R);
	if (mid < R) res += query(mid + 1, r, rt << 1 | 1, L, R);
	pushUp(rt, l, r);
	return res;
}
void solve() {
	int n, q; scanf("%d%d", &n, &q);
	build(0, n - 1, 1);
	while (q--) {
		int c, i, j, v;
		scanf("%d%d%d", &c, &i, &j);
		if (c == 1) {
			scanf("%d", &v);
			update(0, n - 1, 1, i, j, v);
		} else {
			print(query(0, n - 1, 1, i, j), j - i + 1);
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
