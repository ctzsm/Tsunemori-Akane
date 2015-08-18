#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > PIII;
struct UFS {
	int f[205];
	UFS(int n) {
		for (int i = 1; i <= n; ++i) f[i] = i;
	}
	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return false;
		f[fy] = fx;
		return true;
	}
	int find(int x) {
		if (f[x] == x) return x;
		return f[x] = find(f[x]);
	}
};
int n, m, c;
PIII a[6005];
int MST(int len) {
	sort(a, a + len);
	UFS s(n);
	int ans = 0;
	for (int i = 0, j = 0; i < len && j < n - 1; ++i) {
		if (s.merge(a[i].second.first, a[i].second.second)) {
			ans += a[i].first;
			a[j++] = a[i];
		}
	}
	return ans;
}
void solve() {
	scanf("%d%d", &n, &m);
	c = n;
	UFS s(n);
	int l = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		if (s.merge(u, v))
			c --;
		if (c <= 1) {
			if (c == 1) {
				a[l++] = make_pair(w, make_pair(u, v));
				printf("%d\n", MST(l));
				c --;
			} else {
				a[n - 1] = make_pair(w, make_pair(u, v));
				printf("%d\n", MST(n));
			}
		} else {
			a[l++] = make_pair(w, make_pair(u, v));
			printf("-1\n");
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
