#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int n, m, p;
int c[105], d[105];
int f[50001], g[105][50001];
int pf[50001], pg[105][50001];
int getn() {
	int x, y; scanf("%d.%d", &x, &y);
	return x * 100 + y;
}
void out(int x) {
	printf(" %d.%02d", x / 100, x % 100);
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) c[i] = getn();
	for (int i = 1; i <= m; ++i) d[i] = getn();
	p = getn();
	sort(c + 1, c + n + 1);
	sort(d + 1, d + m + 1);
	int V = accumulate(d + 1, d + m + 1, 0) - p;
	memset(f, 0x3f, sizeof f);
	memset(g, -1, sizeof g);
	f[0] = g[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j + c[i] <= V; ++j) {
			if (f[j + c[i]] > f[j] + 1) {
				f[j + c[i]] = f[j] + 1;
				pf[j + c[i]] = c[i];
			}
		}
	}
	int ans = 0x3f3f3f3f, ansi, ansj;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < p; ++j) {
			if (g[i - 1][j] == -1) continue;
			if (g[i][j] < g[i - 1][j]) {
				g[i][j] = g[i - 1][j];
				pg[i][j] = -1;
			}
			if (g[i][j + d[i]] < g[i - 1][j] + 1) {
				g[i][j + d[i]] = g[i - 1][j] + 1;
				pg[i][j + d[i]] = d[i];
				if (j + d[i] >= p) {
					int cur = f[j + d[i] - p] - g[i][j + d[i]];
					if (ans > cur) {
						ans = cur, ansi = j + d[i], ansj = i;
					}
				}
			}
		}
	}
	vector<int> pay, ret;
	int j = ansj, i = ansi;
	while (pg[j][i] != 0) {
		if (pg[j][i] == -1) j--;
		else {
			pay.push_back(pg[j][i]);
			i -= pg[j][i];
			j --;
		}
	}
	i = ansi - p;
	while (pf[i] != 0) {
		ret.push_back(pf[i]);
		i -= pf[i];
	}
	reverse(pay.begin(), pay.end());
	reverse(ret.begin(), ret.end());
	printf("%d", (int)pay.size());
	for (int i = 0; i < pay.size(); ++i) out(pay[i]); printf("\n");
	printf("%d", (int)ret.size());
	for (int i = 0; i < ret.size(); ++i) out(ret[i]); printf("\n");
	return 0;
}
