#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

int n;
std::map<int, int> h;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		h[a]++;
	}
	int x = 0, cnt = 0;
	for (std::map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
		if ((*it).second > x) {
			x = (*it).second;
			cnt = 1;
		} else if ((*it).second == x) {
			cnt ++;
		}
	}
	if (x > ((n + 1) / 2)) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}