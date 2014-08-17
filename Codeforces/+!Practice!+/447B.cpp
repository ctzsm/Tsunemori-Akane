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

char s[1005];
int k, w[26], ps[1005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s%d", s, &k);
	for (int i = 0; i < 26; ++i) scanf("%d", &w[i]);
	int m = 0, tot = 0, n = strlen(s), tot2 = 0;
	for (int i = 0; i < 26; ++i) m = std::max(m, w[i]);
	for (int i = 0; i < n; ++i) tot += (i + 1) * w[s[i] - 'a'];
	for (int i = 0; i < k; ++i) tot2 += (i + 1 + n) * m;
	for (int i = n - 1; i >= 0; --i)
		ps[i] = ps[i + 1] + w[s[i] - 'a'];
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = std::max(ans, tot2 + tot + k * ps[i + 1]);
		tot2 -= m * k;
	}
	printf("%d\n", ans);
	return 0;
}