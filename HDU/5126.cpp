#pragma comment (linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50000;
int nz = 0;
int c[maxn * 2 + 5], sz[maxn * 2 + 5], ans[maxn + 5];
struct node {
	int x, y, z, k, id;
	node() {}
	node(int x, int y, int z, int k, int id):
		x(x), y(y), z(z), k(k), id(id) {}
}lt[maxn * 8 + 5], lx[maxn * 8 + 5], ly[maxn * 8 + 5];
bool cmpx(const node& a, const node& b) {
	return a.x < b.x || (a.x == b.x && a.k < b.k);
}
bool cmpy(const node& a, const node& b) {
	return a.y < b.y || (a.y == b.y && a.k < b.k);
}
inline int lowbit(int x) { return x & -x; }
int query(int x) {
	int res = 0;
	while (x > 0) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}
void add(int x, int v) {
	while (x <= nz) {
		c[x] += v;
		x += lowbit(x);
	}
}
void solve3(int l, int r) {
	if (l >= r) return;
	for (int i = l; i <= r; ++i) {
		int z = ly[i].z;
		if (ly[i].k == 0) add(z, 1);
		else {
			if (ly[i].k == 1) ans[ly[i].id] += query(z);
			else ans[ly[i].id] -= query(z);
		}
	}
	for (int i = l; i <= r; ++i)
		if (ly[i].k == 0) add(ly[i].z, -1);
}
void solve2(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1, ny = 0;
	solve2(l, mid);
	solve2(mid + 1, r);
	for (int i = l; i <= mid; ++i) if (lx[i].k == 0)
		ly[ny++] = lx[i];
	if (ny == 0) return;
	int tny = ny;
	for (int i = mid + 1; i <= r; ++i) if (lx[i].k)
		ly[ny++] = lx[i];
	if (tny == ny) return;
	sort(ly, ly + ny, cmpy);
	solve3(0, ny - 1);
}
void solve1(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1, nx = 0;
	solve1(l, mid);
	solve1(mid + 1, r);
	for (int i = l; i <= mid; ++i) if (lt[i].k == 0)
		lx[nx++] = lt[i];
	if (nx == 0) return;
	int tnx = nx;
	for (int i = mid + 1; i <= r; ++i) if (lt[i].k)
		lx[nx++] = lt[i];
	if (tnx == nx) return;
	sort(lx, lx + nx, cmpx);
	solve2(0, nx - 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int Q, n = 0, j = 0; scanf("%d", &Q); nz = 0;
		for (int i = 0; i < Q; ++i) {
			int x, y, z, px, py, pz, k;
			scanf("%d", &k);
			if (k == 1) {
				scanf("%d%d%d", &x, &y, &z);
				lt[n++] = node(x, y, z, 0, -1);
				sz[nz++] = z;
			} else {
				scanf("%d%d%d%d%d%d", &x, &y, &z, &px, &py, &pz);
				lt[n++] = node(px    , py    , pz    , 1, j);
				lt[n++] = node( x - 1, py    , pz    , 2, j);
				lt[n++] = node(px    ,  y - 1, pz    , 2, j);
				lt[n++] = node(px    , py    ,  z - 1, 2, j);
				lt[n++] = node( x - 1,  y - 1, pz    , 1, j);
				lt[n++] = node( x - 1, py    ,  z - 1, 1, j);
				lt[n++] = node(px    ,  y - 1,  z - 1, 1, j);
				lt[n++] = node( x - 1,  y - 1,  z - 1, 2, j);
				sz[nz++] = z - 1;
				sz[nz++] = pz;
				j ++;
			}
		}
		sort(sz, sz + nz);
		nz = unique(sz, sz + nz) - sz;
		for (int i = 0; i < n; ++i)
			lt[i].z = lower_bound(sz, sz + nz, lt[i].z) - sz + 1;
		memset(ans, 0, sizeof ans);
		solve1(0, n - 1);
		for (int i = 0; i < j; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
