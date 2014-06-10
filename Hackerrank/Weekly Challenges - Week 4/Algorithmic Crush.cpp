#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int maxn = 16600000;
int N, M;
long long a[maxn * 2], lazy[maxn * 2];
int maxrt = 0;
void update(int L, int R, int l, int r, int rt, int v) {
	if (rt >= maxn * 2) return;
	maxrt = std::max(maxrt, rt);
	if (l <= L && R <= r) {
		lazy[rt] += v;
		a[rt] += v;
		return;
	}
	if ((rt << 1) < maxn * 2) lazy[rt << 1]     += lazy[rt];
	if ((rt << 1 | 1) < maxn * 2) lazy[rt << 1 | 1] += lazy[rt];
	if ((rt << 1) < maxn * 2) a[rt << 1]     += lazy[rt];
	if ((rt << 1 | 1) < maxn * 2) a[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
	int m = (L + R) >> 1;
	if (l <= m) update(L,     m, l, r, rt << 1,     v);
	if (r >  m) update(m + 1, R, l, r, rt << 1 | 1, v);
	if ((rt << 1) < maxn * 2)
		a[rt] = a[rt << 1];
	if ((rt << 1 + 1) < maxn * 2)
		a[rt] = std::max(a[rt], a[rt << 1 | 1]);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		update(1, N, l, r, 1, k);
	}
	printf("%lld\n", a[1]);
	return 0;
}