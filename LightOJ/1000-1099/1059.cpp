#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > PIII;
PIII e[100005];
int T, n, m, a;
int f[10005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return false;
	f[fy] = fx;
	return true;
}
void solve() {
	scanf("%d%d%d", &n, &m, &a);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 0; i < m; ++i) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		e[i] = make_pair(c, make_pair(u, v));
	}
	sort(e, e + m);
	int ans1 = a * n, ans2 = n, weight = 0, nair = n;
	for (int i = 0; i < m; ++i) {
		if (merge(e[i].second.first, e[i].second.second)) {
			nair --;
			weight += e[i].first;
			if (ans1 > nair * a + weight) {
				ans1 = nair * a + weight;
				ans2 = nair;
			}
		}
	}
	printf("%d %d\n", ans1, ans2);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
