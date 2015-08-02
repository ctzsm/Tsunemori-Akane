#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, r;
int a[50005], q[50005][2], b[150000];
int t[2 << 19];
void build(int l, int r, int rt) {
	t[rt] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		t[rt] ++;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, l, mid, rt << 1);
	if (mid < R) update(L, R, mid + 1, r, rt << 1 | 1);
}
int query(int x, int l, int r, int rt) {
	if (l == r && l == x)
		return t[rt];
	int mid = (l + r) >> 1;
	if (x <= mid) return query(x, l, mid, rt << 1) + t[rt];
	return query(x, mid + 1, r, rt << 1 | 1) + t[rt];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		int bc = 0;
		scanf("%d%d", &n, &r);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &q[i][0], &q[i][1]);
			b[bc++] = q[i][0];
			b[bc++] = q[i][1];
		}
		for (int i = 0; i < r; ++i) {
			scanf("%d", &a[i]);
			b[bc++] = a[i];
		}
		sort(b, b + bc);
		bc = unique(b, b + bc) - b;
		build(0, bc, 1);
		for (int i = 0; i < n; ++i) {
			int x = lower_bound(b, b + bc, q[i][0]) - b;
			int y = lower_bound(b, b + bc, q[i][1]) - b;
			update(x, y, 0, bc, 1);
		}
		for (int i = 0; i < r; ++i) {
			int x = lower_bound(b, b + bc, a[i]) - b;
			printf("%d\n", query(x, 0, bc, 1));
		}
	}
	return 0;
}
