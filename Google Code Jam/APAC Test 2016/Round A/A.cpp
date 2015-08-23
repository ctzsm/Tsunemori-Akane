#include <bits/stdc++.h>

using namespace std;

int main2() {
	long long k, p = 1;
	scanf("%lld", &k);
	while (k > p) {
		p = 2 * p + 1;
	}
	int cnt = 0;
	while (p > 1) {
		long long p2 = (p - 1) / 2;
		if (k == p2 + 1) break;
		if (k > p2 + 1) {
			k = p - k + 1;
			cnt ++;
		}
		p = p2;
	}
	return cnt & 1;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: %d\n", _, main2());
	}
	return 0;
}
