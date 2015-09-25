#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int t[1 << 19];
void build(int l, int r, int rt) {
	t[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void update(int L, int R, int v, int l, int r, int rt) {
	if (L <= l && r <= R) {
		t[rt] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, v, l, mid, rt << 1);
	if (mid < R) update(L, R, v, mid + 1, r, rt << 1 | 1);
}
int query(int I, int l, int r, int rt) {
	if (l == r) {
		return t[rt];
	}
	int mid = (l + r) >> 1, res = t[rt];
	if (I <= mid) res = max(res, query(I, l, mid, rt << 1));
	else res = max(res, query(I, mid + 1, r, rt << 1 | 1));
	return res;
}
bool h[100005];
int solve() {
	int n; scanf("%d", &n);
	build(1, n * 2, 1);
	for (int i = 1; i <= n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		update(l, r, i, 1, 2 * n, 1);
	}
	memset(h, false, sizeof h);
	int ans = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		int c = query(i, 1, 2 * n, 1);
		if (c && !h[c]) {
			h[c] = true;
			ans ++;
		}
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
