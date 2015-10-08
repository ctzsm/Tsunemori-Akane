#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef map<pair<int, int>, int>::iterator itr;
int n, a[105];
map<pair<int, int>, int> h[105];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		for (int i = 0; i <= n; ++i) h[i].clear();
		h[0][make_pair(0, 1000000)] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				for (itr it = h[j].begin(); it != h[j].end(); ++it) {
					int l = it->first.first, r = it->first.second;
					int len = it->second;
					if (l <= a[i] && a[i] <= r) {
						pair<int, int> p1 = make_pair(a[i], r);
						pair<int, int> p2 = make_pair(l, a[i]);
						if (h[i].find(p1) == h[i].end()) h[i][p1] = 0;
						if (h[i].find(p2) == h[i].end()) h[i][p2] = 0;
						h[i][p1] = max(h[i][p1], len + 1);
						h[i][p2] = max(h[i][p2], len + 1);
						ans = max(ans, len + 1);
					}
				}
			}
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
