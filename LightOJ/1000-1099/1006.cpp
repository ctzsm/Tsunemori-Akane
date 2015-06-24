#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 10000007;
int T, f[10001], n;
int solve() {
	for (int i = 0; i < 6; ++i) scanf("%d", &f[i]);
	for (int i = 0; i < 6; ++i) f[i] %= mod;
	scanf("%d", &n);
	for (int i = 6; i <= n; ++i) {
		f[i] = 0;
		for (int j = 1; j <= 6; ++j)
			f[i] += f[i - j];
		f[i] %= mod;
	}
	return f[n];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: %d\n", _, solve());
	}
	return 0;
}
