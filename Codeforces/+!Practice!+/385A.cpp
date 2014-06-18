#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, c;
int x[105];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans = std::max(ans, x[i] - x[i + 1] - c);
	}
	printf("%d\n", ans);
	return 0;
}