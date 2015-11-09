#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int modPow(int n, int k) {
	long long res = 1, p = n % 1000;
	while (k) {
		if (k & 1) res = res * p % 1000;
		p = p * p % 1000;
		k >>= 1;
	}
	return res;
}
int fit(int n, int k) {
	double l = log10(n + 0.0) * k;
	return pow(10, l + 2 - (long long)l);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, k; scanf("%d%d", &n, &k);
		printf("Case %d: %d %03d\n", _, fit(n, k), modPow(n, k));
	}
	return 0;
}
