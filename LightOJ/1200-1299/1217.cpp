#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1005], a[1005];
int solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	int ans = max(a[0], a[1]);
	int tmp = a[n - 1]; a[n - 1] = 0;
	for (int k = 0; k < 2; ++k) {\
		f[0] = a[0], f[1] = max(a[0], a[1]);
		for (int i = 2; i < n; ++i)
			f[i] = max(f[i - 1], f[i - 2] + a[i]);
		ans = max(ans, f[n - 1]);
		a[0] = 0, a[n - 1] = tmp;
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
