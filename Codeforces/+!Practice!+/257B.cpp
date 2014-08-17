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

int n, m;
bool s[200005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	if (n < m) std::swap(n, m);
	int t = n + m, p = 0, who = 0, pre = (m & 1), now = 0;
	for (int i = 0; i < t; ++i) {
		if (who == 0) now = pre;
		else now = pre ^ 1;
		if (now == 0 && n) s[p++] = now, n--;
		if (now == 1 && m) s[p++] = now, m--;
		who ^= 1;
		pre = now;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < t - 1; ++i) {
		if (s[i] == s[i + 1]) ans1++;
		else ans2 ++;
	}
	// for (int i = 0; i < t; ++i) printf("%d", s[i]); printf("\n");
	printf("%d %d\n", ans1, ans2);
	return 0;
}