#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long b[100005], p;
long long solve() {
	int n; scanf("%d%lld", &n, &p);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", b + i);
	for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
	for (int l = 0, r = 1; r <= n; ++r) {
		while (l <= r && b[r] - b[l] > p) l ++;
		ans += r - l;
	}
	return ans;
}
int main() {
	freopen("the_price_is_correct.txt", "r", stdin);
	freopen("the_price_is_correct.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %lld\n", _, solve());
	return 0;
}
