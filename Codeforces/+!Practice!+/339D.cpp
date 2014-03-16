#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 17;
int n, m;
int a[1 << (N + 1)], tree[1 << (N + 2)];
void build(int l, int r, int id, int o) {
	if (l >= r) {
		tree[id] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, id << 1, o ^ 1);
	build(m + 1, r, id << 1 | 1, o ^ 1);
	if (o) tree[id] = tree[id << 1] ^ tree[id << 1 | 1];
	else tree[id] = tree[id << 1] | tree[id << 1 | 1];
}
void update(int l, int r, int p, int b, int id, int o) {
	if (l >= r) {
		tree[id] = b;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(l, m, p, b, id << 1, o ^ 1);
	else update(m + 1, r, p, b, id << 1 | 1, o ^ 1);
	if (o) tree[id] = tree[id << 1] ^ tree[id << 1 | 1];
	else tree[id] = tree[id << 1] | tree[id << 1 | 1];
}
int main(void) {
//	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= (1 << n); ++i) scanf("%d", &a[i]);
	build(1, 1 << n, 1, !(n & 1));
	for (int i = 0; i < m; ++i) {
		int p, b; scanf("%d%d", &p, &b);
		update(1, 1 << n, p, b, 1, !(n & 1));
		printf("%d\n", tree[1]);
	}
	return 0;
}