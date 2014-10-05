#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
long long C[1005][1005];
void getC() {
	for (int i = 0; i <= 1002; ++i)
		for (int j = 0; j <= i; ++j)
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}
struct pnt {
	int x, y;
	pnt() {}
	pnt(int _x, int _y): x(_x), y(_y) {}
	void print() {
		printf("%d %d\n", x, y);
	}
	void read() {
		scanf("%d%d", &x, &y);
	}
} p[1005];
int cnt[1005][1005], who[1005][1005];
int x[1005], y[1005], nowx[1005], nowy[1005];
long long getArea(pnt &i, pnt &j) {
	return (abs(0LL + i.x - j.x) + 1LL) * (abs(0LL + i.y - j.y) + 1LL);
}
int N, K;
int u = 0, d = 0, l = 0, r = 0;
int ul, ur, dl, dr;
void calc() {
	long long ans = C[N][K];
	int need = N - K;
	if (ul && dr && need - 2 >= 0)
		ans = (ans - C[N - 2][need - 2] + mod) % mod;
	if (ul && (d + dl) && (r + ur)) {
		int total = ul + d + dl + r + ur + dr;
		for (int i = 1; i <= (d + dl); ++i)
			for (int j = 1; j <= (r + ur); ++j) {
				if (need - i - j - 1 < 0) break;
				ans = (ans - C[d + dl][i] * C[r + ur][j] % mod * C[N - total][need - i - j - 1] % mod + mod) % mod;
			}
	}
	if (u && dl && (r + dr + ur)) {
		int total = u + dl + r + dr + ur + ul;
		for (int i = 1; i <= u; ++i)
			for (int j = 1; j <= r + dr + ur; ++j) {
				if (need - i - j - 1 < 0) break;
				ans = (ans - C[u][i] * C[r + dr + ur][j] % mod * C[N - total][need - i - j - 1] % mod + mod) % mod;
			}
	}
	if (u && l && dr) {
		int total = u + l + dr + ul + dl;
		for (int i = 1; i <= u; ++i)
			for (int j = 1; j <= l; ++j) {
				if (need - i - j - 1 < 0) break;
				ans = (ans - C[u][i] * C[l][j] % mod * C[N - total][need - i - j - 1] % mod + mod) % mod;
			}
	}
	if (u && l && d && (r + ur)) {
		int total = u + l + d + r + ur + ul + dl + dr;
		for (int i = 1; i <= u; ++i)
			for (int j = 1; j <= l; ++j) {
				if (need - i - j < 0) break;
				for (int k = 1; k <= d; ++k) {
					if (need - i - j - k < 0) break;
					for (int m = 1; m <= r + ur; ++m) {
						if (need - i - j - k - m < 0) break;
						ans = (ans - C[u][i] * C[l][j] % mod * C[d][k] % mod * C[r + ur][m] % mod
						       * C[N - total][need - i - j - k - m] % mod + mod) % mod;
					}
				}
			}
	}
	if (ur && dl && (need - 2) >= 0) {
		ans = (ans - C[N - 2 - ul - u][need - 2] + mod) % mod;
	}
	if (ur && l && (d + dr)) {
		int total = ur + l + d + dr + ul + u + dl;
		for (int i = 1; i <= l; ++i)
			for (int j = 1; j <= d + dr; ++j) {
				if (need - i - j - 1 < 0) break;
				ans = (ans - C[l][i] * C[d + dr][j] % mod * C[N - total][need - i - j - 1] % mod + mod) % mod;
			}
	}
	printf("%lld\n", (ans % mod + mod) % mod);
}
int main() {
	getC();
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) p[i].read();
	if (K == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < N; ++i) x[i] = p[i].x, y[i] = p[i].y;
	sort(x, x + N), sort(y, y + N);
	int nx = unique(x, x + N) - x, ny = unique(y, y + N) - y;
	for (int i = 0; i < N; ++i) {
		nowx[i] = lower_bound(x, x + nx, p[i].x) - x + 1;
		nowy[i] = lower_bound(y, y + ny, p[i].y) - y + 1;
		cnt[nowy[i]][nowx[i]] = 1;
		who[nowy[i]][nowx[i]] = i;
	}
	ul = cnt[1][1], ur = cnt[1][nx], dl = cnt[ny][1], dr = cnt[ny][nx];
	for (int i = 2; i < nx; ++i) u += cnt[1][i], d += cnt[ny][i];
	for (int i = 2; i < ny; ++i) l += cnt[i][1], r += cnt[i][nx];
	calc();
	return 0;
}