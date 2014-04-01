#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>

const int maxn = 10000000;
long long modPow(long long a, long long k, long long m) {
    long long res = 1, p = a % m;
    while (k) {
        if (k & 1) res = res * p % m;
        p = p * p % m;
        k >>= 1;
    }
    return res;
}

long long pow(long long x, long long k) {
    long long res = 1, p = x;
    while (k) {
        if (k & 1) res = res * p;
        p = p * p;
        k >>= 1;
    }
    return res;
}

long long extgcd(long long a, long long b, long long &x, long long &y, long long n) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, x, y, n);
    long long t = x; x = y; y = ((t - (a / b * y % n)) % n + n) % n;
    // std::cout << "y = " << y << std::endl;
    return d;
}

long long CRT(long long b[], long long w[], int k) {
    long long d, x, y, m, a = 0, n = 1;
    for (int i = 0; i < k; ++i) n *= w[i];
    for (int i = 0; i < k; ++i) {
        m = n / w[i];
        d = extgcd(w[i], m, x, y, n);
        a = (a + ((y * m % n) * b[i] % n)) % n;
    }
    while (a < 0) a += n;
    return a;
}

int phi[10000005];
int prime[5000000] = {2}, np = 1;
int T;
long long m[20], a[20], pri[20], c[20];
int main() {
    for (int i = 1; i <= maxn; i++) phi[i] = i;
    for (int i = 2; i <= maxn; i += 2) phi[i] /= 2;
    for (int i = 3; i <= maxn; i += 2) if (phi[i] == i) {
            for (int j = i; j <= maxn; j += i)
                phi[j] = phi[j] / i * (i - 1);
            prime[np++] = i;
        }
    freopen("in", "r", stdin);
    std::cin >> T;
    while (T--) {
        long long n1, k1, n2, k2, n;
        std::cin >> n1 >> k1 >> n2 >> k2 >> n;
        if (n == 1) {
            std::cout << 0 << std::endl;
            continue;
        }
        if (k1 == 0 || (n2 == 0 && k2 != 0)) {
            std::cout << 1 << std::endl;
            continue;
        }
        long long sn = (long long)std::sqrt(n), num = 0;
        for (int i = 0; i < np; ++i) {
            if (prime[i] > sn || n <= 1) break;
            if (n % prime[i] == 0) {
                m[num] = 1;
                pri[num] = prime[i];
                c[num] = 0;
                while (n % prime[i] == 0) {
                    m[num] *= prime[i];
                    c[num] ++;
                    n /= prime[i];
                }
                num++;
            }
        }
        if (n > 1) {
            m[num] = n;
            c[num] = 1;
            pri[num] = n;
            num++;
        }
        for (int i = 0; i < num; ++i) {
            long long gcd = std::__gcd(m[i], n1);
            if (gcd == 1) {
                a[i] = modPow(n1, k1 * modPow(n2, k2, phi[m[i]]) % phi[m[i]], m[i]);
            } else {
            	if (n1 == 0) {
            		a[i] = 0;
            		continue;
            	}
            	long long cnt = 0, t = n1;
            	while(t % pri[i] == 0) {
            		cnt++;
            		t /= pri[i];
            	}
                if (std::log(cnt) + std::log(k1) + k2 * std::log(n2) > std::log(24)) {
                    a[i] = 0;
                } else {
                    a[i] = modPow(n1, k1 * pow(n2, k2), m[i]);
                }
            }
        }
        std::cout << CRT(a, m, num) << std::endl;
    }
    return 0;
}