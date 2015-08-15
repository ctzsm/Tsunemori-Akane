#include <cstdio>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		long long W, M = 1; scanf("%lld", &W);
		while (!(W & 1)) {
			W >>= 1;
			M <<= 1;
		}
		if (M == 1)
			printf("Impossible\n");
		else
			printf("%lld %lld\n", W, M);
	}
	return 0;
}
