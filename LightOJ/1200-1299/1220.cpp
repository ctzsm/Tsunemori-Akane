#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50000;
int prime[maxn], pcnt = 0;
bool check[maxn];
void getPrime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!check[i]) prime[pcnt++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			check[i * prime[i]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		long long n; scanf("%lld", &n);
		int sign = n > 0 ? 1 : -1; n = llabs(n);
		int sn = sqrt(n), ans = -1;
		for (int i = 0; i <= sn && i < pcnt; ++i) {
			int cnt = 0;
			while (n % prime[i] == 0) {
				n /= prime[i];
				cnt ++;
			}
			if (cnt) {
				if (ans == -1)
					ans = cnt;
				else
					ans = __gcd(ans, cnt);
			}
			if (n < 2) break;
		}
		if (n > 1) ans = 1;
		if (sign == -1)
			while (ans % 2 == 0) ans /= 2;
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
