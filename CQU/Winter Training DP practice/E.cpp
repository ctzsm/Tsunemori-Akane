#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n, h[MAXN], l[MAXN], r[MAXN];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
		l[0] = 0, r[n + 1] = n + 1;
		for (int i = 1; i <= n; ++i) {
			int x = i - 1;
			l[i] = i;
			while (x >= 1 && h[x] >= h[i]) {
				l[i] = l[x];
				x = l[x] - 1;
			}
		}
		for (int i = n; i >= 1; --i) {
			int x = i + 1;
			r[i] = i;
			while (x <= n && h[x] >= h[i]) {
				r[i] = r[x];
				x = r[x] + 1;
			}
		}
		// for (int i = 1; i <= n; ++i) printf("%d ", l[i]); printf("\n");
		// for (int i = 1; i <= n; ++i) printf("%d ", r[i]); printf("\n");
		long long ans = 0;
		for (int i = 1; i <= n; ++i) ans = max(ans, (r[i] - l[i] + 1LL) * h[i]);
		cout << ans << endl;
	}
	return 0;
}