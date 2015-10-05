#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[15];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		a[0] = 2;
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		n = unique(a, a + n + 1) - a;
		int ans = 0;
		for (int i = 1; i < n; ++i)
			ans += (a[i] - a[i - 1] - 1) / 5 + 1;
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
