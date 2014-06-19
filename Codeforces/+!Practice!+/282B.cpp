#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>

long long n;
long long a[1000005], g[1000005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	scanf("%lld", &n);
#else
	scanf("%I64d", &n);
#endif
	for (int i = 0; i < n; ++i)
#ifndef ONLINE_JUDGE
		scanf("%lld%lld", &a[i], &g[i]);
#else
		scanf("%I64d%I64d", &a[i], &g[i]);
#endif
	long long sum = std::accumulate(a, a + n, 0);
	for (int i = 0; i <= n; ++i) {
		long long x = sum - (n - i) * 1000;
		if (-500 <= x && x <= 500) {
			for (int j = 0; j < i; ++j) printf("A");
			for (int j = i; j < n; ++j) printf("G");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}