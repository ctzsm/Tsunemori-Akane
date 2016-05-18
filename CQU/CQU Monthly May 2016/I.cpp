#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int T, n;
int primes[maxn + 5], pcnt = 0;
bool is_not_prime[maxn + 5];
bool f[maxn + 5];
void get_prime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!is_not_prime[i]) primes[pcnt ++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * primes[j] > maxn) break;
			is_not_prime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
	for (int i = 0; i < pcnt && primes[i] * primes[i] <= maxn; ++i) {
		f[primes[i] * primes[i]] = true;
	}
}
int main() {
	freopen("in", "r", stdin);
	get_prime();
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			puts(f[x] ? "YES" : "NO");
		}
	}
	return 0;
}
