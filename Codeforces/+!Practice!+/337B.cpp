#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int a, b, c, d;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ac = a * c / std::__gcd(a, c);
	if (b * ac / a >= d * ac / c) {
		b = b * ac / a;
		d = d * ac / c;
		int g = std::__gcd(b - d, b);
		printf("%d/%d\n", (b - d) / g, (b - d == 0) ? 1 : b / g);
		return 0;
	}
	int bd = b * d / std::__gcd(b, d);
	a = a * bd / b;
	c = c * bd / d;
	int g = std::__gcd(a - c, a);
	printf("%d/%d\n", (a - c) / g, (a - c == 0) ? 1 : a / g);
	return 0;
}