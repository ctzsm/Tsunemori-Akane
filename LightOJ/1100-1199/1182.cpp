#include <cstdio>
#include <algorithm>

using namespace std;

bool solve() {
	int n; scanf("%d", &n);
	return __builtin_popcount(n) & 1;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "odd" : "even");
	return 0;
}
