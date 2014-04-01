#include <iostream>
#include <cstdio>
#include <algorithm>

const int mod = 1000000007;
long long modPow(long long a, long long k, long long m) {
	long long res = 1, p = a;
	while (k) {
		if (k & 1) res = res * p % m;
		p = p * p % m;
		k >>= 1;
	}
	return res;
}

int N;
int a[100005];
long long f[100005];
int main() {
	std::cin >> N;
	int ec = 0, oc = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		if (a[i] & 1) oc ++;
		else ec ++;
	}
	// long long to = 1, foc = 1;
	// for (int i = 1; i <= oc; ++i) {
	// 	foc = foc * i % mod;
	// 	f[i] = foc;
	// } 
	// f[0] = 1;
	// for (int i = 2; i <= oc; i += 2) {
	// 	to += (foc * modPow(f[i], mod - 2, mod) % mod) * modPow(f[oc - i], mod - 2, mod) % mod;
	// }
	// long long answer = modPow(2, ec, mod) * to % mod;
	// std::cout << (answer - 1 + mod) % mod << std::endl;
	std::cout << (modPow(2, ec + std::max(oc - 1, 0), mod) - 1 + mod) % mod << std::endl;
	return 0;
}