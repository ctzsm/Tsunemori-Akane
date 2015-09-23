#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		printf("Case %d: ", _);
		if ((r1 + c1) % 2 != (r2 + c2) % 2) {
			puts("impossible");
			continue;
		}
		if (r1 - r2 == c1 - c2 || r1 - r2 == c2 - c1)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
