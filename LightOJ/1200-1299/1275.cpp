#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int N, C; scanf("%d%d", &N, &C);
		int x = 0;
		if (N) {
			x = C / (N * 2);
			if (1.0 * x * (C - x * N) < 1.0 * (x + 1) * (C - (x + 1) * N))
				x = x + 1;
		}
		printf("Case %d: %d\n", _, x);
	}
	return 0;
}
