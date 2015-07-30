#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, q, a[100005], t[1 << 18];
int L, R;
inline void pushUp(int rt) {
	t[rt] = t[rt << 1];
	t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		t[rt] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushUp(rt);
}
int query(int l, int r, int rt) {
	if (L <= l && r <= R) return t[rt];
	int mid = (l + r) >> 1;
	int res = 0x3f3f3f3f;
	if (L <= mid) res = min(res, query(l, mid, rt << 1));
	if (mid < R) res = min(res, query(mid + 1, r, rt << 1 | 1));
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		build(1, n, 1);
		while (q--) {
			scanf("%d%d", &L, &R);
			printf("%d\n", query(1, n, 1));
		}
	}
	return 0;
}
