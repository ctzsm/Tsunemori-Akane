#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int sum[1 << 18], cnt[100005], a[100005];
int op[100005], b[100005];
void update(int idx, int L, int R, int val, int rt) {
	sum[rt] += val;
	if (L == R) return;
	int mid = (L + R) >> 1;
	if (idx <= mid) update(idx, L, mid, val, rt << 1);
	else update(idx, mid + 1, R, val, rt << 1 | 1);
}
int query1(int x, int L, int R, int rt) {
	if (L == R) return L == x ? 0 : sum[rt];
	int mid = (L + R) >> 1;
	if (x <= mid)
		return query1(x, L, mid, rt << 1);
	return sum[rt << 1] + query1(x, mid + 1, R, rt << 1 | 1);
}
int query2(int x, int L, int R, int rt) {
	if (L == R) return L;
	int mid = (L + R) >> 1;
	if (sum[rt << 1] >= x)
		return query2(x, L, mid, rt << 1);
	return query2(x - sum[rt << 1], mid + 1, R, rt << 1 | 1);
}
int main() {
	freopen("in", "r", stdin);
	int n, m = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", op + i, b + i);
		if (op[i] != 4) a[m++] = b[i];
	}
	sort(a, a + m);
	m = unique(a, a + m) - a;
	for (int i = 0; i < n; ++i) {
		int x = b[i];
		if (op[i] != 4) x = lower_bound(a, a + m, x) - a;
		if (op[i] == 1) {
			update(x, 0, m - 1, 1, 1);
			cnt[x] ++;
		}
		if (op[i] == 2) {
			update(x, 0, m - 1, -1, 1);
			cnt[x] --;
		}
		if (op[i] == 3)
			printf("%d\n", query1(x, 0, m - 1, 1) + 1);
		if (op[i] == 4)
			printf("%d\n", a[query2(x, 0, m - 1, 1)]);
		if (op[i] == 5) {
			int j = query1(x, 0, m - 1, 1);
			printf("%d\n", a[query2(j, 0, m - 1, 1)]);
		}
		if (op[i] == 6) {
			int j = query1(x, 0, m - 1, 1);
			printf("%d\n", a[query2(j + cnt[x] + 1, 0, m - 1, 1)]);
		}
	}
	return 0;
}
