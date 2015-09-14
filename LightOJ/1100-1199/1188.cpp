#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int bucket[100005];
struct qnode {
	int l, r, idx;
	qnode() {}
	qnode(int l, int r, int i): l(l), r(r), idx(i) {}
	bool operator < (const qnode& a) const {
		if (bucket[l] != bucket[a.l])
			return bucket[l] < bucket[a.l];
		return (bucket[l] & 1) ? r < a.r : r > a.r;
	}
}q[50005];
int c[100005], a[100005];
int ans[50005], cnt = 0;
inline void remove(int x) {
	c[a[x]] --;
	if (!c[a[x]]) cnt --;
}
inline void add(int x) {
	c[a[x]] ++;
	if (c[a[x]] == 1) cnt ++;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int N, Q; scanf("%d%d", &N, &Q);
		for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
		int S = (int)sqrt(N);
		for (int i = 1; i <= N; ++i) bucket[i] = (i - 1) / S + 1;
		for (int i = 0; i < Q; ++i) {
			int l, r; scanf("%d%d", &l, &r);
			q[i] = qnode(l, r, i);
		}
		sort(q, q + Q);
		int L = 1, R = 0;
		for (int i = 0; i < Q; ++i) {
			int l = q[i].l, r = q[i].r, idx = q[i].idx;
			while (L < l) remove(L++);
			while (L > l) add(--L);
			while (R < r) add(++R);
			while (R > r) remove(R--);
			ans[idx] = cnt;
		}
		for (int i = L; i <= R; ++i) remove(i);
		printf("Case %d:\n", _);
		for (int i = 0; i < Q; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
