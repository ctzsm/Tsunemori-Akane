#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Fraction{
	long long x, y;
	Fraction() {}
	Fraction(long long _x, long long _y): x(_x), y(_y) {}
	Fraction operator + (const Fraction& a) {
		Fraction res;
		long long gcd = __gcd(y, a.y);
		res.x = x * (a.y / gcd) + a.x * (y / gcd), res.y = y / gcd * a.y;
		long long gcd1 = __gcd(res.x, res.y);
		res.x /= gcd1, res.y /= gcd1;
		return res;
	}
	Fraction operator * (const Fraction& a) {
		Fraction res;
		long long gcd1 = __gcd(a.x, y);
		long long gcd2 = __gcd(x, a.y);
		res.x = (x / gcd2) * (a.x / gcd1), res.y = (y / gcd1) * (a.y / gcd2);
		return res;
	}
	Fraction de() {
		long long gcd = __gcd(x, y);
		Fraction res(x / gcd, y / gcd);
		return res;
	}
	void print() {
		if (x == 0) {
			printf("0\n");
			return;
		}
		if (x == 1 && y == 1) {
			printf("1\n");
			return;
		}
		printf("%lld/%lld\n", x, y);
	}
};
int T;
Fraction f[30][160], oos(1, 6), zero(0, 1);
bool g[30][160];
Fraction dfs(int n, int k) {
	if (g[n][k]) return f[n][k];
	g[n][k] = true;
	Fraction res(0, 1);
	for (int i = 1; i < 7; ++i) {
		if (k > i)
			res = res + dfs(n - 1, k - i);
	}
	return f[n][k] = res * oos;
}
void solve() {
	int n, k; scanf("%d%d", &n, &k);
	if (k <= n) {
		printf("1\n");
		return;
	}
	if (n * 6 < k) {
		printf("0\n");
		return;
	}
	Fraction res(0, 1);
	for (int i = k; i <= n * 6; ++i)
		res = res + dfs(n, i);
	res.print();
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 7; ++i) f[1][i] = oos;
	for (int i = 7; i < 151; ++i) f[1][i] = zero;
	for (int i = 0; i < 151; ++i) g[1][i] = true;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
