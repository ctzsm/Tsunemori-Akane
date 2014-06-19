#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n, k;
std::set<long long> h;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		h.insert(a);
	}
	int ans = 0;
	for (std::set<long long>::iterator it = h.begin(); it != h.end(); it = h.begin()) {
		long long x = *it, cnt = 1;
		h.erase(x);
		while (h.find(x * k) != h.end()) {
			x = x * k;
			h.erase(x);
			cnt ++;
		}
		ans += (cnt + 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}