#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first
#define y second
int n, sp;
pair<int, int> p[1005];
struct seg {
	int a, b;
	long long len;
	seg() {}
	seg(int i, int j) {
		a = p[i].x - p[j].x, b = p[i].y - p[j].y;
		len = 1LL * a * a + 1LL * b * b;
		int gcd = __gcd(abs(a), abs(b));
		a /= gcd, b /= gcd;
		if (b < 0) {
			b = -b;
			a = -a;
		}
	}
	bool operator < (const seg& x) const {
		if (len == x.len)
			return a * x.b < x.a * b;
		return len < x.len;
	}
}s[500000];
inline int c(int x) {
	return x * (x - 1) / 2;
}
int solve() {
	sp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
	}
	sort(p, p + n);
	int three = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			s[sp++] = seg(i, j);
			int x = p[i].x + p[j].x;
			int y = p[i].y + p[j].y;
			if ((x & 1) || (y & 1)) continue;
			x /= 2, y /= 2;
			pair<int, int> g = make_pair(x, y);
			int k = lower_bound(p, p + n, g) - p;
			if (p[k] == g)
				three ++;
		}
	sort(s, s + sp);
	int cnt = 1, ans = 0;
	seg& now = s[0];
	for (int i = 1; i < sp; ++i) {
		if (now.len == s[i].len && now.a * s[i].b == s[i].a * now.b) {
			cnt ++;
		} else {
			ans += c(cnt);
			now = s[i];
			cnt = 1;
		}
	}
	ans += c(cnt);
	ans -= three;
	return ans / 2;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
