#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
bool check[maxn];
int prime[maxn / 10], pcnt = 0;
void getPrime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!check[i]) prime[pcnt++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int solve() {
	long long n; scanf("%lld", &n);
	while (n % 2 == 0) n /= 2;
	int sn = sqrt(n), ans = 1;
	for (int i = 1; prime[i] <= sn && i < pcnt; ++i) {
		int cnt = 0;
		while (n % prime[i] == 0) {
			n /= prime[i];
			cnt ++;
		}
		if (cnt) {
			ans *= cnt + 1;
			sn = sqrt(n);
		}
		if (n < 2) break;
	}
	if (n > 1)
		ans *= 2;
	return ans - 1;
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
