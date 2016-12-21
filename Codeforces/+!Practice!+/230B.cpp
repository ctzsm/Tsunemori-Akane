#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
int n, primes[maxn + 5], pcnt = 0;
bool not_prime[maxn + 5];
void get_primes() {
	for (int i = 2; i <= maxn; ++i) {
		if (!not_prime[i]) primes[pcnt++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * primes[j] > maxn) break;
			not_prime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
	not_prime[1] = true;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	get_primes();
	for (int i = 0; i < n; ++i) {
		long long x; scanf("%lld", &x);
		long long sx = (long long)round(sqrt(1.0 * x));
		bool ans = sx * sx == x && !not_prime[sx];
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
