#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n;
int c[1005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	int ans[2] = {0, 0}, who = 0;
	int i = 0, j = n - 1;
	while (i <= j) {
		if (c[i] > c[j]) {
			ans[who] += c[i++];
		} else {
			ans[who] += c[j--];
		}
		who = who ^ 1;
	}
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}