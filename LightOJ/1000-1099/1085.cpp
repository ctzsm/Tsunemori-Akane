#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int n, a[100005], b[100005], c[100005];
inline int lowbit(int x) { return x & (-x); }
void update(int x, int v) {
	while (x <= n) {
		c[x] += v;
		if (c[x] >= mod) c[x] -= mod;
		x += lowbit(x);
	}
}
int sum(int x) {
	int res = 0;
	while (x) {
		res += c[x];
		if (res >= mod) res -= mod;
		x -= lowbit(x);
	}
	return res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) b[i] = a[i];
	sort(b, b + n);
	int m = unique(b, b + n) - b;
	int ans = 0;
	memset(c, 0, (n + 2) * sizeof(int));
	for (int i = 0; i < n; ++i) {
		int x = lower_bound(b, b + m, a[i]) - b + 1;
		int v = sum(x - 1) + 1;
		if (v >= mod) v -= mod;
		ans += v;
		if (ans >= mod) ans -= mod;
		update(x, v);
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
