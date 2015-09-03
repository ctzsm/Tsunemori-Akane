#include <cstdio>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int k, x = 0; scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			x ^= v - u - 1;
		}
		printf("Case %d: %s\n", _, x ? "Alice" : "Bob");
	}
	return 0;
}
