#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
struct node {
	int l, r, sum;
}T[maxn * 40];
int a[maxn + 5], b[maxn + 5], rt[maxn + 5], tcnt = 1;
void update(int l, int r, int pre, int& now, int idx) {
	T[now = tcnt++] = T[pre];
	T[now].sum ++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (idx <= mid) update(l, mid, T[pre].l, T[now].l, idx);
	else update(mid + 1, r, T[pre].r, T[now].r, idx);
}
int query(int l, int r, int t1, int t2, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int sum = T[T[t2].l].sum - T[T[t1].l].sum;
	if (sum >= k)
		return query(l, mid, T[t1].l, T[t2].l, k);
	return query(mid + 1, r, T[t1].r, T[t2].r, k - sum);
}
int main() {
	freopen("in", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) b[i] = a[i];
	sort(b, b + n);
	int nb = unique(b, b + n) - b;
	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(b, b + nb, a[i]) - b + 1;
		update(1, n, rt[i], rt[i + 1], idx);
	}
	while (m --) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", b[query(1, n, rt[l - 1], rt[r], k) - 1]);
	}
	return 0;
}
