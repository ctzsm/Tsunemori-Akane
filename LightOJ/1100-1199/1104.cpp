#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int solve() {
	int n; scanf("%d", &n);
	double p = 1.0;
	for (int i = 1; i < n; ++i) {
		p *= 1.0 * (n - i) / n;
		if (p <= 0.5)
			return i;
	}
	return n;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
