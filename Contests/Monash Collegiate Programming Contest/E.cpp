#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2000000;
bool is_not_prime[maxn + 5];
int primes[maxn / 2], pcnt = 0;
void get_prime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!is_not_prime[i]) primes[pcnt++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * primes[j] > maxn) break;
			is_not_prime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
int main() {
	// freopen("in", "r", stdin);
	get_prime();
	long long k; cin >> k;
	if (k == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < pcnt; ++i) {
		if (k % primes[i]) continue;
		int cnt = 0;
		while (k % primes[i] == 0) {
			k /= primes[i];
			cnt ++;
		}
		if (cnt > 1) {
			printf("0\n");
			return 0;
		}
		if (k == 1) break;
	}
	if (k == 1) {
		printf("1\n");
		return 0;
	}
	long long sk = sqrt((long double)k);
	for (long long i = max(0LL, sk - 1000); i < sk + 1000; ++i)
		if (sk * sk == k) {
			printf("0\n");
			return 0;
		}
	printf("1\n");
	return 0;
}
