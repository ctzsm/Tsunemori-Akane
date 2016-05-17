#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T> inline void read(T &x){
	x = 0; T f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
int sum[1 << 21], cnt[1000005];
void update(int idx, int L, int R, int val, int rt) {
	sum[rt] += val;
	if (L == R) return;
	int mid = (L + R) >> 1;
	if (idx <= mid) update(idx, L, mid, val, rt << 1);
	else update(idx, mid + 1, R, val, rt << 1 | 1);
}
int query1(int x, int L, int R, int rt) {
	if (L == R) return sum[rt];
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
	int n, m, tot = 0; read<int>(n); read<int>(m);
	for (int i = 0; i < m; ++i) {
		int op, x; read<int>(op);
		if (op != 3 && op != 4) read<int>(x);
		if (op == 1) {
			if (cnt[x] == 0) {
				update(x, 0, n - 1, 1, 1);
				cnt[x] ++, tot ++;
			}
		}
		if (op == 2) {
			if (cnt[x] == 1) {
				update(x, 0, n - 1, -1, 1);
				cnt[x] --, tot --;
			}
		}
		if (op == 3) {
			if (!tot) printf("-1\n");
			else printf("%d\n", query2(1, 0, n - 1, 1));
		}
		if (op == 4) {
			if (!tot) printf("-1\n");
			else printf("%d\n", query2(tot, 0, n - 1, 1));
		}
		if (op == 5) {
			int j = query1(x, 0, n - 1, 1);
			if (j - cnt[x] == 0) printf("-1\n");
			else printf("%d\n", query2(j - cnt[x], 0, n - 1, 1));
		}
		if (op == 6) {
			int j = query1(x, 0, n - 1, 1);
			if (j == tot) printf("-1\n");
			else printf("%d\n", query2(j + 1, 0, n - 1, 1));
		}
		if (op == 7)
			printf("%d\n", cnt[x] ? 1 : -1);
	}
	return 0;
}
