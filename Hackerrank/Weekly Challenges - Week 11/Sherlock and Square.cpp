#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

const long long mod = 1000000007;

int T, N;
long long modPow(int x, int k) {
	long long res = 1, p = x;
	while (k) {
		if (k & 1) res = res * p % mod;
		p = p * p % mod;
		k >>= 1;
	}
	return res;
}
void solve() {
	scanf("%d", &N);
	printf("%lld\n", (modPow(2, N + 1) + 2) % mod);

}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}