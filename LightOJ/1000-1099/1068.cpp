#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long base[20] = {1};
int a, b, k;
int f[11][85][85];
int d[20];
int g(int x) {
	if (x == 0) return 1;
	int i = 1;
	while (x) {
		d[i++] = x % 10;
		x /= 10;
	}
	int res = 0, s = 0, t = 0;
	for (i--; i > 0; --i) {
		int sp = (k - s) % k, st = (k - t) % k;
		for (int j = 0; j < d[i]; ++j) {
			res += f[i - 1][sp][st];
			sp--; if (sp < 0) sp += k;
			st -= base[i - 1] % k; if (st < 0) st += k;
		}
		s = (s + d[i]) % k;
		t = (t + d[i] * base[i - 1]) % k;
	}
	return res + (s % k == 0 && t % k == 0);
}
int solve() {
	scanf("%d%d%d", &a, &b, &k);
	if (k >= 85) return 0;
	memset(f, 0, sizeof f);
	f[0][0][0] = 1;
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j) {
			int sj = j * base[i - 1] % k;
			for (int s = 0; s < k; ++s) {
				int sp = (s + j) % k;
				for (int t = 0, st = sj; t < k; ++t) {
					f[i][sp][st] += f[i - 1][s][t];
					st ++; if (st >= k) st -= k;
				}
			}
		}
	return g(b) - g(a - 1);
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 15; ++i) base[i] = base[i - 1] * 10;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
