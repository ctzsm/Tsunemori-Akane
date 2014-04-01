#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <map>

// const int mod = 1000000007;
const int mod = 10007;
long long modPow(long long a, long long k, long long m) {
    long long res = 1, p = a % m;
    while (k) {
        if (k & 1) res = res * p % m;
        p = p * p % m;
        k >>= 1;
    }
    return res;
}

int T;
long long K, n, R;
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
    std::cin >> T;
    while (T--) {
    	std::cin >> K >> n >> R;
    	R %= mod;
    	long long answer = 0;
    	long long tR = R;
    	std::map<long long, long long> map;
    	for (int i = 1; i <= n; ++i) {
    		long long power = modPow(i, K, mod);
    		long long term = power * tR % mod;
    		answer = (answer + term) % mod;
    		map[answer]++;
    		tR = tR * R % mod;
    	}
    	std::cout << answer << std::endl;
    	for (std::map<long long, long long>::iterator it = map.begin(); it != map.end(); ++it)
    		std::cout << (*it).first << " " << (*it).second << std::endl;
    }
    return 0;
}