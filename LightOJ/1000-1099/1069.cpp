#include <cstdio>
#define ABS(x) ((x) < 0 ? -(x) : (x))
int main() {
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int a, b; scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", _, (ABS(a - b) + a) * 4 + 19);
	}
	return 0;
}
