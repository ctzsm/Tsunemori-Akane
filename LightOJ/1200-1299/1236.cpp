#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
bool check[maxn + 1];
int prime[maxn / 10], pcnt = 0;
void getPrime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!check[i]) prime[pcnt++] = i;
		for (int j = 0;j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int solve() {
	long long n; scanf("%lld", &n);
	long long sn = sqrt(n), ans = 1;
	for (int i = 0; i < pcnt && prime[i] <= sn; ++i) {
		int cnt = 0;
		while (n % prime[i] == 0) {
			n /= prime[i];
			cnt ++;
		}
		if (cnt) {
			ans *= 2 * cnt + 1;
		}
		if (n < 2) break;
		if (cnt) {
			sn = sqrt(n);
		}
	}
	if (n > 1) ans *= 3;
	return ans / 2 + 1;
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
