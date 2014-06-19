#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
int cnt[8];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		cnt[a] ++;
	}
	if (cnt[5] > 0 || cnt[7] > 0 || cnt[2] < cnt[4] || cnt[3] + (cnt[2] - cnt[4]) != cnt[6] || cnt[1] != cnt[4] + cnt[6]) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < cnt[4]; ++i) {
		printf("1 2 4\n");
		cnt[2] --;
	}
	for (int i = 0; i < cnt[6]; ++i) {
		if (cnt[2] == 0)
			printf("1 3 6\n");
		else {
			printf("1 2 6\n");
			cnt[2] --;
		}
	}
	return 0;
}