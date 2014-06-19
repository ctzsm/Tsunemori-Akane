#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
int x[100005], y[100005];
int cx[100005], cy[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; ++i) {
		cx[x[i]]++;
		cy[y[i]]++;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d %d\n", n - 1 + cx[y[i]], n - 1 - cx[y[i]]);
	}
	return 0;
}