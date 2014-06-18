#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
int cnt[3];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		if (x == 25) cnt[0]++;
		if (x == 50) {
			if (cnt[0] >= 1) {
				cnt[0] --;
				cnt[1] ++;
			} else {
				printf("NO\n");
				return 0;
			}
		}
		if (x == 100) {
			if (cnt[1] >= 1 && cnt[0] >= 1) {
				cnt[1] --, cnt[0] --;
			} else if (cnt[0] >= 3) {
				cnt[0] -= 3;
			} else {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}