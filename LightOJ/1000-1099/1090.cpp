#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, r, p, q;
int calc(int n, int r, int s, int d) {
	int ans = 0;
	while (n) { ans += n / d; n /= d; }
	while (r) { ans -= r / d; r /= d; }
	while (s) { ans -= s / d; s /= d; }
	return ans;
}
int calc2(int p, int q, int d) {
	int ans = 0;
	while (p % d == 0) { ans++; p /= d; }
	return ans * q;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d%d%d", &n, &r, &p, &q);
		int s = n - r;
		int ans2 = calc(n, r, s, 2) + calc2(p, q, 2);
		int ans5 = calc(n, r, s, 5) + calc2(p, q, 5);
		printf("Case %d: %d\n", _, min(ans2, ans5));
	}
	return 0;
}
