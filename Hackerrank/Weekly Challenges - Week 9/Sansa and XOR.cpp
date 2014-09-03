#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int a[100005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		int ans = 0;
		long long cnt = 0;
		for (int i = 0; i < N; ++i) {
			if ((cnt + N - i) & 1) ans ^= a[i];
			cnt += N - i;
			cnt -= i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}