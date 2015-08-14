#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, q, t[1 << 18];
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &t[rt]);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
int update(int l, int r, int x, int rt) {
	if (l == r) {
		int res = t[rt];
		t[rt] = 0;
		return res;
	}
	int mid = (l + r) >> 1, res = 0;
	if (x <= mid) res = update(l, mid, x, rt << 1);
	else res = update(mid + 1, r, x, rt << 1 | 1);
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
	return res;
}
void update(int l, int r, int x, int v, int rt) {
	if (l == r) {
		t[rt] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(l, mid, x, v, rt << 1);
	else update(mid + 1, r, x, v, rt << 1 | 1);
	t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
int query(int l, int r, int L, int R, int rt) {
	if (L <= l && r <= R)
		return t[rt];
	int mid = (l + r) >> 1;
	int res = 0;
	if (L <= mid) res += query(l, mid, L, R, rt << 1);
	if (mid < R) res += query(mid + 1, r, L, R, rt << 1 | 1);
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &q);
		build(0, n - 1, 1);
		while (q--) {
			int o, u, v; scanf("%d", &o);
			switch(o) {
				case 1: scanf("%d", &u); printf("%d\n", update(0, n - 1, u, 1)); break;
				case 2: scanf("%d%d", &u, &v); update(0, n - 1, u, v, 1); break;
				case 3: scanf("%d%d", &u, &v); printf("%d\n", query(0, n - 1, u, v, 1)); break;
			}
		}
	}
	return 0;
}
