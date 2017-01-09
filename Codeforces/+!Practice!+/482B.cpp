#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, m;
int cl[maxn], cr[maxn], cq[maxn];
int a[maxn][30], b[maxn], tr[2 << 18];
void build(int l, int r, int rt) {
	if (l == r) {
		tr[rt] = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	tr[rt] = tr[rt << 1] & tr[rt << 1 | 1];
}
int query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) {
		return tr[rt];
	}
	int mid = (l + r) >> 1, res = 0;
	if (mid >= L)
		res = query(l, mid, rt << 1, L, R);
	if (mid < R) {
		if (mid >= L) {
			res &= query(mid + 1, r, rt << 1 | 1, L, R);
		} else {
			res = query(mid + 1, r, rt << 1 | 1, L, R);
		}
	}
	return res;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", cl + i, cr + i, cq + i);
		for (int j = 0; j < 30; ++j) {
			if (cq[i] & (1 << j)) {
				a[cl[i]][j] ++;
				a[cr[i] + 1][j] --;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int x = 0;
		for (int j = 29; j >= 0; --j) {
			a[i][j] += a[i - 1][j];
			x = (x << 1) + (a[i][j] > 0);
		}
		b[i] = x;
	}
	// for (int i = 1; i <= n; ++i)
	// 	printf("%d ", b[i]);
	// printf("\n");
	build(1, n, 1);
	for (int i = 0; i < m; ++i) {
		if (query(1, n, 1, cl[i], cr[i]) != cq[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}
