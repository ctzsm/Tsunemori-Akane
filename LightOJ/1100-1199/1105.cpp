#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long f[50][2];
char s[50];
void init() {
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i < 50; ++i) {
		f[i][1] += f[i - 1][0];
		f[i][0] += f[i - 1][0] + f[i - 1][1];
	}
}
void solve() {
	int n; scanf("%d", &n);
	int l = 1;
	for (; f[l][1] <= n; ++l);
	memset(s, 0, sizeof s);
	for (int i = 0; i < l - 2; ++i) {
		if (f[l - i - 1][1] <= n) {
			s[i] = '1';
			n -= f[l - i - 1][1];
		} else {
			s[i] = '0';
		}
	}
	printf("%s\n", s);
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
