#include <iostream>
#include <cstdio>
#include <cstring>
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

int T;
long long n, k;
long long fp[1005] = {1}, p1[1005], n1[1005];
int main() {
	freopen("in", "r", stdin);
	std::cin >> T;
	for (int i = 1; i <= 1005; ++i) fp[i] = fp[i-1] * i % mod;
    while(T--) {
    	std::cin >> n >> k;
    	n %= mod;
    	if (k == 0) {
    		std::cout << n << std::endl;
    		continue;
    	}
    	memset(n1, 0, sizeof(n1));
    	n1[0] = 1;
    	for (long long i = k + 1, j = n + k + 1; i > 0; --i, --j) {
    		n1[0] = n1[0] * j % mod;
    		n1[0] = n1[0] * modPow(i, mod - 2, mod) % mod;
    	}
    	for (long long i = 1, j = n + k + 1; i <= k; ++i, --j) {
    		n1[i] = n1[i - 1] * (j - k - 1) % mod;
    		n1[i] = n1[i] * modPow(j, mod - 2, mod) % mod;
    	}
    	long long answer = 0;
    	for (int i = 0; i <= k; ++i) {
    		p1[i] = fp[k + 1] * modPow(fp[i], mod - 2, mod) % mod;
    		p1[i] = p1[i] * modPow(fp[k + 1 - i], mod - 2, mod) % mod;
    	}
    	for (int i = 1; i <= k; ++i) {
    		for (int j = 0; j < i; ++j) {
    			long long t = (j & 1) ? (mod - 1) : 1;
    			t = t * modPow(i - j, k, mod) % mod;
    			t = t * n1[i] % mod;
    			t = t * p1[j] % mod;
    			answer = (answer + t) % mod;
    			// std::cout << t << std::endl;
    		}
    	}
    	std::cout << answer << std::endl;
    }
    return 0;
}