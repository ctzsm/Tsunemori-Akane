#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50000;
int prime[maxn / 2], pcnt = 0;
bool isNotPrime[maxn], f[100005];
void init() {
	for (int i = 2; i < maxn; ++i) {
		if (!isNotPrime[i]) {
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
			prime[pcnt++] = i;
		}
	}
}
int solve() {
	int a, b; scanf("%d%d", &a, &b);
	if (a < 2) a = 2; 
	int r = b - a + 1, sb = (int)sqrt(b);
	for (int i = 0; i < r; ++i) f[i] = true;
	for (int i = 0; i < pcnt && prime[i] <= sb; ++i) {
		long long j = max(a / prime[i], 2) * prime[i];
		if (j - a < 0) j += prime[i];
		for (; j <= b; j += prime[i]) {
			f[j - a] = false;
		}
	}
	int ans = 0;
	for (int i = (a & 1) ^ 1; i < r; i += 2) ans += f[i];
	return ans + (a == 2 && r > 0);
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
