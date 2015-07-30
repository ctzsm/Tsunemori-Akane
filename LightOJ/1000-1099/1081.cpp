#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, q, a[505][505];
int t[1024][1024];
int L, R, U, D;
inline void pushUpy(int rtx, int rty) {
	t[rtx][rty] = max(t[rtx][rty << 1], t[rtx][rty << 1 | 1]);
}
inline void pushUpx(int u, int d, int rtx, int rty) {
	if (u == d) {
		t[rtx][rty] = max(t[rtx << 1][rty], t[rtx << 1 | 1][rty]);
		return;
	}
	int mid = (u + d) >> 1;
	pushUpx(u, mid, rtx, rty << 1);
	pushUpx(mid + 1, d, rtx, rty << 1 | 1);
	t[rtx][rty] = max(t[rtx << 1][rty], t[rtx << 1 | 1][rty]);
}
void buildy(int u, int d, int l, int rtx, int rty) {
	if (u == d) {
		t[rtx][rty] = a[l][u];
		return;
	}
	int mid = (u + d) >> 1;
	buildy(u, mid, l, rtx, rty << 1);
	buildy(mid + 1, d, l, rtx, rty << 1 | 1);
	pushUpy(rtx, rty);
}
void buildx(int l, int r, int rtx) {
	if (l == r) {
		buildy(1, n, l, rtx, 1);
		return;
	}
	int mid = (l + r) >> 1;
	buildx(l, mid, rtx << 1);
	buildx(mid + 1, r, rtx << 1 | 1);
	pushUpx(1, n, rtx, 1);
}
int queryy(int u, int d, int rtx, int rty) {
	if (U <= u && d <= D) {
		return t[rtx][rty];
	}
	int mid = (u + d) >> 1;
	int res = -1;
	if (U <= mid) res = max(res, queryy(u, mid, rtx, rty << 1));
	if (mid < D) res = max(res, queryy(mid + 1, d, rtx, rty << 1 | 1));
	return res;
}
int query(int l, int r, int u, int d, int rtx, int rty) {
	if (L <= l && r <= R) {
		return queryy(u, d, rtx, rty);
	}
	int mid = (l + r) >> 1;
	int res = -1;
	if (L <= mid) res = max(res, query(l, mid, u, d, rtx << 1, rty));
	if (mid < R) res = max(res, query(mid + 1, r, u, d, rtx << 1 | 1, rty));
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &a[i][j]);
		buildx(1, n, 1);
		while (q--) {
			int I, J, S; scanf("%d%d%d", &I, &J, &S);
			L = I, R = I + S - 1;
			U = J, D = J + S - 1;
			printf("%d\n", query(1, n, 1, n, 1, 1));
		}
	}
	return 0;
}
