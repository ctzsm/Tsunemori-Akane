#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		int x1, y1, x2, y2, n;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
		while (n--) {
			int x, y; scanf("%d%d", &x, &y);
			bool ans = x1 <= x && x <= x2 &&
					y1 <= y && y <= y2;
			puts(ans ? "Yes" : "No");
		}
	}
	return 0;
}
