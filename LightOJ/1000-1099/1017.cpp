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
}p[100];
int T, n, w, K;
int f[105][105];
int solve() {
	scanf("%d%d%d", &n, &w, &K);
	for (int i = 0; i < n; ++i) p[i].scan();
	sort(p, p + n);
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i) {
		int j = i - 1;
		while (j >= 0 && p[j].y + w >= p[i].y) {
			for (int k = 1; k <= K; ++k)
				f[i][k] = max(f[i][k], f[j][k]);
			j --;
		}
		if (j < 0)
			for (int k = 1; k <= K; ++k)
				f[i][k] = i - j;
		else
			for (int k = 1; k <= K; ++k)
				f[i][k] = max(f[i][k], f[j][k - 1] + i - j);
	}
	return f[n - 1][K];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _  = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
