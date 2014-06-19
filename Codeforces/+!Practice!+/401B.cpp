#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int x, k;
bool f[4005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &x, &k);
	for (int i = 0; i < k; ++i) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int n1, n2; scanf("%d%d", &n2, &n1);
			f[n2] = f[n1] = true;
		} else {
			int n2; scanf("%d", &n2);
			f[n2] = true;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < x; ++i)
		if (!f[i]) ans2 ++;
	for (int i = 1; i < x; ++i) {
		if (!f[i]) {
			ans1 ++;
			if (i + 1 < x && !f[i + 1]) i ++;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}