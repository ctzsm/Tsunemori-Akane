#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, m; scanf("%d%d", &n, &m);
		long long ans = 1LL * m * n / 2;
		printf("Case %d: %lld\n", _, ans);
	}
	return 0;
}
