#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
}p[20];
int T, n, ans;
int f[1 << 16], mask[16][16];
int dfs(int curMask) {
	if (f[curMask] != -1) return f[curMask];
	int res = n;
	for (int i = 0; i < n; ++i) if (curMask & (1 << i)) {
		for (int j = i + 1; j < n; ++j) if (curMask & (1 << j)) {
			res = min(res, dfs(curMask & (~mask[i][j])) + 1);
		}
		break;
	}
	return f[curMask] = res;
}
int solve() {
	scanf("%d", &n);
	int m = 1 << n;
	for (int i = 0; i < n; ++i) p[i].scan();
	for (int i = 1; i < m; ++i) f[i] = -1;
	for (int i = 0; i < n; ++i) {
		f[1 << i] = 1;
		for (int j = i + 1; j < n; ++j) {
			mask[i][j] = 0;
			f[(1 << i) | (1 << j)] = 1;
			for (int k = 0; k < n; ++k) {
				int a = p[j].y - p[i].y, b = p[j].x - p[i].x;
				int c = p[k].y - p[i].y, d = p[k].x - p[i].x;
				if (a * d == b * c)
					mask[i][j] |= 1 << k;
			}
		}
	}
	return dfs(m - 1);
}
int main() {
	scanf("%d", &T);
	for (int _  = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
