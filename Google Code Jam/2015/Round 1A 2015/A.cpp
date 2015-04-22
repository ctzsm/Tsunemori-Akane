#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[1005];
void solve() {
	scanf("%d", &n);
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i) ans1 += max(0, a[i - 1] - a[i]);
	int mg = 0;
	for (int i = 1; i < n; ++i) mg = max(mg, a[i - 1] - a[i]);
	for (int i = 1; i < n; ++i) ans2 += min(a[i - 1], mg);
	printf("%d %d\n", ans1, ans2);
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
