#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, d;
int solve() {
	scanf("%d%d", &n, &d);
	int r = d % n, c = 1;
	while (r) {
		r = (r * 10 + d) % n;
		c ++;
	}
	return c;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
