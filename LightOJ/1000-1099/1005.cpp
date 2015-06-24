#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, k;
long long solve() {
	scanf("%d%d", &n, &k);
	if (k > n) return 0;
	long long res = 1;
	for (int i = n, j = 1; j <= k; ++j, --i)
		res = res * i / j * i;
	return res;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
