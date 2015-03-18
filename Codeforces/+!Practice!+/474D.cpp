#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int T, k;
int f[100005];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &T, &k);
	f[0] = 1;
	for (int i = 1; i <= 100000; ++i) {
		if (i - k >= 0) f[i] = (f[i] + f[i - k]) % mod;
		f[i] = (f[i] + f[i - 1]) % mod;
	}
	for (int i = 1; i <= 100000; ++i) f[i] = (f[i] + f[i - 1]) % mod;
	while (T--) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", ((f[b] - f[a - 1]) % mod + mod) % mod);
	}
	return 0;
}