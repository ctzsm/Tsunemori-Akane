#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

const int maxn = 100000;
bool isNotPrime[maxn + 1] = {true, true};
int F[20] = {0}, E[20] = {1};
int prime[maxn / 2], idx = 0;
void sieve() {
    for (int i = 2; i <= maxn; ++i) 
        if (!isNotPrime[i]) {
            for (int j = i + i; j <= maxn; j += i) isNotPrime[j] = true;
            prime[idx++] = i;
        }
}

void solve(long long x) {
    long long t = x;
    int c2 = 0, c5 = 0;
    while (t % 2 == 0) {
        t /= 2;
        c2 ++;
    }
    while (t % 5 == 0) {
        t /= 5;
        c5 ++;
    }
    long long zero = std::max(c5, std::max(c2 - 2, 0)), four = 1, rem = 4 % t;
    for (int i = 1; ; ++i) {
        if (rem == 0) {
            std::cout << "               " << x << " " << four << " " << zero << std::endl;
            if (std::sqrt(x) - four >= 0)
                std::cout << std::sqrt(x) << " " << four << std::endl;
            // std::cout << four * 2 + zero << std::endl;
            break;
        }
        rem = (rem * 10 + 4) % t;
        four ++;
        if (i % 100000000 == 0) std::cout << i << std::endl;
    }
}
bool check(long long x, long long len) {
    long long l = len, rem = 0;
    while (l) {
        if (l >= 19) {

        }
    }
    return rem == 0;
}
void solve2(long long x) {    
    long long t = x;
    int c2 = 0, c5 = 0;
    while (t % 2 == 0) {
        t /= 2;
        c2 ++;
    }
    while (t % 5 == 0) {
        t /= 5;
        c5 ++;
    }
    long long zero = std::max(c5, std::max(c2 - 2, 0)), four = 1, rem = 4 % t;
}
int T;
int main() {
    sieve();
    // freopen("in", "r", stdin);
    // std::cin >> T;
    // while (T--) {
    //     long long x;
    //     std::cin >> x;
    //     solve(x);
    // }
    for (int i = 0; i <= 100; ++i) {
        bool flag = true;
        if (flag) solve(prime[i]);
    }
    return 0;
}