#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int calc(int x) {
	if (x == 0) return 0;
	return x / 3 * 2 + (x % 3 == 2);
}
int solve() {
	int a, b; scanf("%d%d", &a, &b);
	return calc(b) - calc(a - 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
