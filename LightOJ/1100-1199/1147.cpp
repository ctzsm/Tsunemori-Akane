#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int a[105];
long long v[50005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int sum = accumulate(a, a + n, 0);
		int lim = sum / 2, hn = n / 2;
		memset(v, 0, sizeof v); v[0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = lim, l = lim - a[i]; j >= a[i]; --j, --l) {
				v[j] |= v[l] << 1;
			}
		}
		for (int i = lim; i >= 0; --i) {
			if ((v[i] & (1LL << hn)) || (v[i] & (1LL << (hn + (n & 1))))) {
				printf("Case %d: %d %d\n", _, i, sum - i);
				break;
			}
		}
	}
	return 0;
}
