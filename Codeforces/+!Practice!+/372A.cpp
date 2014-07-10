#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
int s[500005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
	std::sort(s, s + n);
	int ans = n / 2;
	for (int i = (n - 1) / 2, j = n - 1; i >= 0; --i) {
		if (j > (n - 1) / 2 && s[j] >= 2 * s[i]) j--;
		else ans ++;
	}
	printf("%d\n", ans);
	return 0;
}