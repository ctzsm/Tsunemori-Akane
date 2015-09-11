#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:", _);
		unsigned long long n; scanf("%llu", &n);
		long long m = n * 10 / 9;
		for (long long x = m - 10; x <= m + 10; ++x) {
			if (x - x / 10 == n) printf(" %lld", x);
		}
		printf("\n");
	}
	return 0;
}
