#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, P, Q; scanf("%d%d%d", &n, &P, &Q);
		int ans = 0, s = 0;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			if (s + x > Q || i >= P) continue;
			s += x;
			ans ++;
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
