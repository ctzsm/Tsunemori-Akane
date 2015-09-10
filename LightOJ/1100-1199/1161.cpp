#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long cnt[10005], ans[10005];
long long solve() {
	int n; scanf("%d", &n);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		for (int j = 1; j * j <= x; ++j) {
			if (x % j == 0) {
				cnt[j] ++;
				if (x / j != j)
					cnt[x / j] ++;
			}
		}
	}
	for (int i = 10000; i > 0; --i) {
		ans[i] = cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) * (cnt[i] - 3) / 24;
		for (int j = i + i; j < 10001; j += i)
			ans[i] -= ans[j];
	}
	return ans[1];
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
