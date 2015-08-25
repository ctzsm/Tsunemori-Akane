#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int solve() {
	scanf("%d", &n);
	map<int, int> h;
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		h[x]++;
	}
	int res = n;
	for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
		int c = (*it).first, m = (*it).second;
		int r = m % (c + 1);
		res += r == 0 ? 0 : c + 1 - r;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
