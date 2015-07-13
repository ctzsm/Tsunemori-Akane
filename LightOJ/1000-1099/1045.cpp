#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, base;
int solve() {
	scanf("%d%d", &n, &base);
	if (n < 2) return 1;
	double a = 0.5 * log(2 * M_PI * n);
	double b = n * (log(n) - 1);
	return (a + b) / log(base) + 1;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
