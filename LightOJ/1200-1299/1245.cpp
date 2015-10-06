#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		int sn = sqrt(n);
		long long ans = 0, pre = n;
		for (int i = 1; i <= sn; ++i) {
			long long now = n / (i + 1);
			ans += i * (pre - now) + n / i;
			pre = now;
			if (n / i == i) ans -= i;
		}
		printf("Case %d: %lld\n", _, ans);
	}
	return 0;
}
