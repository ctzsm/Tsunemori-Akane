#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, p[1005];
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	sort(p, p + n, greater<int>());
	int ans = p[0];
	for (int m = p[0]; m >= 1; --m) {
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += (p[i] - 1) / m;
		ans = min(ans, cnt + m);
	}
	printf("%d\n", ans);
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}