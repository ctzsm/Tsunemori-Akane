#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		int a, b; scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		if (a == 1) {
			printf("%d\n", b);
			continue;
		}
		if (a == 2) {
			int r = b % 4 < 2 ? (b % 4) : 2;
			printf("%d\n", 2 * (b / 4 * 2 + r));
			continue;
		}
		printf("%d\n", (a * b + 1) / 2);
	}
	return 0;
}
