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

int n, x;
int t[2005], h[2005], m[2005], v[2005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) scanf("%d%d%d", &t[i], &h[i], &m[i]);
	int ans = 0;
	for (int b = 0; b <= 1; ++b) {
		memset(v, 0, sizeof v);
		int cur = b, able = x, cnt = 0;
		for (int i = 0; i < n; ++i) {
			int mass = -1, id = -1;
			for (int j = 0; j < n; ++j)
				if (!v[j] && t[j] == cur && h[j] <= able && mass < m[j]) id = j, mass = m[j];
			if (id == -1) break;
			v[id] = 1;
			able += mass;
			cur ^= 1;
			cnt ++;
		}
		ans = std::max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}