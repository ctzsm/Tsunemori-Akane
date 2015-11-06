#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long a[105], lb[100];
long long solve() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	memset(lb, 0, sizeof lb);
	for (int i = 0; i < n; ++i) {
		for (int j = 62; j >= 0; --j) {
			if (a[i] & (1LL << j)) {
				if (!lb[j]) { lb[j] = a[i]; break; }
				else a[i] ^= lb[j];
			}
		}
	}
	long long ans = 0;
	for (int i = 62; i >= 0; --i) {
		if ((ans & (1LL << i)) && (lb[i] & (1LL << i)))
			continue;
		ans ^= lb[i];
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
