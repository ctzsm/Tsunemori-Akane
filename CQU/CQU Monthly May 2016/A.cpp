#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int n, a[1000005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int ans = a[n - 1] - a[0], o = 0;
		for (int i = 1; i < n; ++i) o = max(o, a[i] - a[i - 1]);
		for (int i = 2; i < n; ++i) ans = min(ans, a[i] - a[i - 2]);
		printf("Case %d: %d\n", _, max(o, ans));
	}
	return 0;
}
