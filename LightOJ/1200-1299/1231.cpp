#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 100000007;
int c[55], a[55];
long long ans[1005], tmp[1005];
long long solve() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i) scanf("%d", c + i);
	memset(ans, 0, sizeof ans);
	for (int i = 0, j = 0; i <= k && j <= c[0]; i += a[0], ++j)
		ans[i] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= k; ++j) tmp[j] = ans[j];
		for (int j = 1, p = a[i]; p <= k && j <= c[i]; p += a[i], ++j)
			for (int l = 0; l + p <= k; ++l) {
				tmp[l + p] += ans[l];
				if (tmp[l + p] >= mod) tmp[l + p] -= mod;
			}
		for (int j = 0; j <= k; ++j) ans[j] = tmp[j];
	}
	return ans[k];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
