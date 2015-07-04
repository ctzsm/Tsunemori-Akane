#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		scanf("%d", &n);
		int go = 0, s = 0;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			if (x > 0) go++;
			s += abs(x);
		}
		if (go) {
			int gcd = __gcd(go, s);
			printf("%d/%d\n", s / gcd, go / gcd);
		} else printf("inf\n");
	}
	return 0;
}
