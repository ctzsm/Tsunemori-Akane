#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

long long f[2005][2005];
void init() {
	for (int i = 1; i <= 2000; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j == 0) f[i][j] = 1;
			else if (i == 2 && j == 1) f[i][j] = 1;
			else {
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
			}
		}
	}
}
void solve() {
	int a, b; scanf("%d-%d", &a, &b);
	long long ans2 = 0;
	for (int i = 0; i < b; ++i) ans2 = (ans2 + f[b][i]) % mod;
	if (b == 0) ans2 = 1;
	printf("%lld %lld\n", f[a][b], ans2);
}
int main() {
	init();
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}