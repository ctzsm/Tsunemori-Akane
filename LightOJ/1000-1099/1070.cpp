#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

map<int, unsigned long long> h;
int s, p, n;
unsigned long long pow(int a, int k) {
	unsigned long long res = 1, p = a;
	while (k) {
		if (k & 1) res *= p;
		p *= p;
		k >>= 1;
	}
	return res;
}
unsigned long long calc(int n) {
	if (h.find(n) != h.end())
		return h[n];
	unsigned long long res = 0;
	if (n & 1) {
		unsigned long long a = calc(n / 2);
		unsigned long long b = calc(n / 2 + 1);
		res = a * b - s * pow(p, n / 2);
	} else {
		unsigned long long a = calc(n / 2);
		res = a * a - 2 * pow(p, n / 2);
	}
	return h[n] = res;
}
unsigned long long solve() {
	h.clear();
	scanf("%d%d%d", &s, &p, &n);
	if (n == 0) return 2;
	h[1] = s;
	return calc(n);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %llu\n", _, solve());
	return 0;
}
