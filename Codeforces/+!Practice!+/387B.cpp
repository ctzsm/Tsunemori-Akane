#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n, m;
int a[3005], b[3005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
	int ans = 0;
	for (int i = 0, j = 0; i < n && j < m; ++i) {
		while (j < m && b[j] < a[i]) j++;
		if (j < m) ans ++, j++;
	}
	printf("%d\n", n - ans);
	return 0;
}