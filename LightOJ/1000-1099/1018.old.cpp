#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
	bool operator < (const pnt& p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
}p[20];
int T, n, ans;
int f[1 << 16];
bool online[16][16][16];
int dfs(int mask) {
	if (f[mask] != -1) return f[mask];
	int& res = f[mask];
	res = n;
	for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
		for (int j = i + 1; j < n; ++j) if (mask & (1 << j)) {
			int mask2 = mask - (1 << i) - (1 << j);
			for (int k = j + 1; k < n; ++k)
				if ((mask2 & (1 << k)) && online[i][j][k])
					mask2 -= 1 << k;
			res = min(res, dfs(mask2) + 1);
		}
		break;
	}
	return res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) p[i].scan();
	memset(f, -1, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; ++i) f[1 << i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) f[(1 << i) | (1 << j)] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				online[i][j][k] = (p[j].y - p[i].y) * (p[k].x - p[i].x) == 
				(p[k].y - p[i].y) * (p[j].x - p[i].x);
	return dfs((1 << n) - 1);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _  = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
