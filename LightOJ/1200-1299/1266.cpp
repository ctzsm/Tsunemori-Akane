#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1024;
int C[maxn][maxn];
bool flag[maxn][maxn];
inline int lowbit(int x) { return x & -x; }
void update(int x, int y, int v = 1) {
	while (x < maxn) {
		int ty = y;
		while (ty < maxn) {
			C[x][ty] += v;
			ty += lowbit(ty);
		}
		x += lowbit(x);
	}
}
int query(int x, int y) {
	int res = 0;
	while (x) {
		int ty = y;
		while (ty) {
			res += C[x][ty];
			ty -= lowbit(ty);
		}
		x -= lowbit(x);
	}
	return res;
}
int query(int x1, int y1, int x2, int y2) {
	return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x1 - 1, y2) - query(x2, y1 - 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		memset(C, 0, sizeof C);
		memset(flag, false, sizeof flag);
		int q; scanf("%d", &q);
		while (q--) {
			int c, x1, y1, x2, y2;
			scanf("%d", &c);
			if (c) {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				x1 ++, y1 ++, x2 ++, y2 ++;
				printf("%d\n", query(x1, y1, x2, y2));
			} else {
				scanf("%d%d", &x1, &y1);
				x1 ++, y1 ++;
				if (!flag[x1][y1]) {
					update(x1, y1);
					flag[x1][y1] = true;
				}
			}
		}
	}
	return 0;
}
