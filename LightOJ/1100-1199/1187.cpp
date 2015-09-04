#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1 << 18], b[100005];
void build(int l, int r, int rt) {
	if (l == r) {
		f[rt] = 1; return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	f[rt] = f[rt << 1] + f[rt << 1 | 1];
}
int query(int l, int r, int rt, int x) {
	if (l == r) {
		f[rt] = 0;
		return l;
	}
	int mid = (l + r) >> 1, res = 0;
	if (f[rt << 1] >= x) res = query(l, mid, rt << 1, x);
	else res = query(mid + 1, r, rt << 1 | 1, x - f[rt << 1]);
	f[rt] = f[rt << 1] + f[rt << 1 | 1];
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		build(1, n, 1);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		for (int i = n - 1; i > 0; --i)
			query(1, n, 1, i - b[i] + 1);
		printf("Case %d: %d\n", _, query(1, n, 1, 1));
	}
	return 0;
}
