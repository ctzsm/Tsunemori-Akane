#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

int n, a[105], cnt[105];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		bool add = true;
		for (int j = 0; j < ans; ++j) {
			if (cnt[j] <= a[i]) {
				cnt[j] ++;
				add = false;
				break;
			}
		}
		if (add) {
			cnt[ans++] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}