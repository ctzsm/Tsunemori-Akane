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
		long long a, b, L;
		scanf("%lld%lld%lld", &a, &b, &L);
		long long lcm = a * b / __gcd(a, b);
		if (L % lcm == 0) {
			long long c = L / lcm, g;
			while ((g = __gcd(c, lcm)) != 1)
				c *= g, lcm /= g;
			printf("Case %d: %lld\n", _, c);
		} else {
			printf("Case %d: impossible\n", _);
		}
	}
	return 0;
}
