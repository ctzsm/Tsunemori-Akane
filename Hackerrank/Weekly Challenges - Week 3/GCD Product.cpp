#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;
const int N = 15000000;

bool isNotPrime[N + 5];
int prime[N / 3], idx = 0;
long long binpow(long long a, long long n) {
	if (n == 0) return 1;
	if (n % 2 == 1) return (long long)a * binpow(a, n - 1) % MOD;
	int t = binpow(a, n / 2);
	return (long long)t * t % MOD;
}
void getPrime() {
	for (int i = 2; i <= N; ++i) {
		if (!isNotPrime[i]) {
			prime[idx++] = i;
			for (int j = i + i; j <= N; j += i) isNotPrime[j] = true;
		}
	}
}
long long calc(long long a, long long b) {
	long long res = 1;
	if (a > b) swap(a, b);
	for (int j = 0; prime[j] <= a && j < idx; ++j) {
		long long p = prime[j];
		while (p <= a) {
			res = res * binpow(prime[j], (a / p) * (b / p)) % MOD;
			p *= prime[j];
		}
	}
	return res;
}
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", (int)calc(n, m));
}
int main() {
	getPrime();
	solve();
	return 0;
}