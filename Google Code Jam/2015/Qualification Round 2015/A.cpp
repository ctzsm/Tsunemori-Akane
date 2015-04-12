#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n;
int p[1005];
char s[1005];
void solve() {
	scanf("%d%s", &n, s);
	int ans = 0, sum = 0;
	for (int i = 0; i <= n; ++i) {
		int x = s[i] - '0';
		if (sum < i) {
			ans += i - sum;
			sum = i;
		}
		sum += x;
	}
	printf("%d\n", ans);
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}