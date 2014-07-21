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

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if (a < c && b < c) {
			printf("NO\n"); continue;
		}
		if (c % std::__gcd(a, b) == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}