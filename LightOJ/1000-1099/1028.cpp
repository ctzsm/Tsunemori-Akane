#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000001;
int T;
bool isNotPrime[maxn];
int prime[maxn / 3], p = 0;
void getPrime() {
	for (int i = 2; i < maxn; ++i) {
		if (!isNotPrime[i]) {
			prime[p++] = i;
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		long long n, ans = 1; scanf("%lld", &n);
		long long sn = sqrt(n) + 1.1;
		for (int i = 0; i < p && prime[i] < sn && n > 1; ++i) {
			int c = 0;
			while (n % prime[i] == 0) {
				n /= prime[i];
				c++;
			}
			if (c) {
				ans *= c + 1;
				sn = sqrt(n) + 1.1;
			}
		}
		if (n > 1) ans *= 2;
		printf("Case %d: %lld\n", _, ans - 1);
	}
	return 0;
}
