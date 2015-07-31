#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005], op[3];
int g[100005];
char f[1 << 18];
void build(int l, int r, int rt) {
	f[rt] = 0;
	if (l == r) {
		g[l] = rt;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		f[rt] ^= 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, l, mid, rt << 1);
	if (mid < R) update(L, R, mid + 1, r, rt << 1 | 1);
}
int query(int x) {
	int res = s[x] == '1';
	x = g[x];
	while (x) {
		if (f[x]) res ^= 1;
		x >>= 1;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		build(1, n, 1);
		int m; scanf("%d", &m);
		while (m --) {
			scanf("%s", op);
			if (op[0] == 'I') {
				int x, y; scanf("%d%d", &x, &y);
				update(x, y, 1, n, 1);
			} else {
				int x; scanf("%d", &x);
				printf("%d\n", query(x));
			}
		}
	}
	return 0;
}
