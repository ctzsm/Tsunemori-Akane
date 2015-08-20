#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, W;
int solve() {
	scanf("%d%d", &n, &W);
	map<int, int> h, g;
	h[0] = 1;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
			if (0LL + (*it).first + x > W) break;
			g[(*it).first + x] += (*it).second;
		}
		for (map<int, int>::iterator it = g.begin(); it != g.end(); ++it)
			h[(*it).first] += (*it).second;
		g.clear();
	}
	int ans = 0;
	for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it)
		ans += (*it).second;
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
