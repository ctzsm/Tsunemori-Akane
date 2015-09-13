#include <cstdio>
#include <algorithm>

using namespace std;

int solve() {
	long long n, k; scanf("%lld%lld", &n, &k);
	long long res = 0;
	for (int i = 2; i <= n; ++i) {
		res = (res + k) % i;
	}
	return res + 1;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
