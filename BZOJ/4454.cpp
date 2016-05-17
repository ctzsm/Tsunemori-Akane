#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
const int maxs = 1000;
unsigned int a[2000], b[2000], dl[maxn];
unsigned short ds[maxn][2], g[maxs][maxs];
int prime[maxn / 5], pcnt = 0;
bool is_not_prime[maxn];
void get_prime() {
	for (int i = 0; i < maxs; ++i) g[i][0] = g[0][i] = g[i][i] = i;
	for (int i = 1; i < maxs; ++i)
		for (int j = i + 1; j < maxs; ++j)
			g[i][j] = g[j][i] = g[i][j - i];
	for (int i = 2; i < maxn; ++i) {
		if (!is_not_prime[i]) {
			prime[pcnt ++] = i;
			ds[i][0] = ds[i][1] = 1, dl[i] = i;
		}
		for (int j = 0; j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			int x = i * prime[j];
			is_not_prime[x] = true;
			ds[x][0] = ds[i][0], ds[x][1] = ds[i][1], dl[x] = dl[i];
			if (ds[i][0] * prime[j] < maxs) ds[x][0] *= prime[j];
			else if (ds[i][1] * prime[j] < maxs) ds[x][1] *= prime[j];
			else dl[x] *= prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}
inline unsigned int gcd(unsigned int x, unsigned int y) {
	if (x == 0) return y;
	if (y == 0) return x;
	unsigned int res = 1;
	for (int i = 0; i < 2; ++i) {
		unsigned int e = ds[x][i], f = 1;
		if (e < maxs) f = g[e][y % e];
		else if (y % e == 0) f = e;
		res *= f, y /= f;
	}
	unsigned int e = dl[x], f = 1;
	if (e < maxs) f = g[e][y % e];
	else if (y % e == 0) f= e;
	return res * f;
}
int main() {
	freopen("in", "r", stdin);
	get_prime();
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%u", a + i);
		for (int j = 0; j < m; ++j) scanf("%u", b + j);
		unsigned int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans += gcd(a[i], b[j]) ^ i ^ j;
		printf("%u\n", ans);
	}
	return 0;
}
