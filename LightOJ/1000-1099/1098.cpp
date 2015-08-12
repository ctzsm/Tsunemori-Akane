#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

inline long long c(int x) {
	return 1LL * x * (x + 1) / 2;
}
long long solve() {
	int n; scanf("%d", &n);
	long long res = 0, sn = (long long)sqrt(n + 0.5);
	for (int i = 2; i <= sn; ++i) {
		res += (c(n / i) - c(n / (i + 1))) * (i - 1);
		if (i < sn)
			res += (n / i - 1) * i;
	}
	if (sn > 1 && n / sn != sn)
		res += (n / sn - 1) * sn;
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
