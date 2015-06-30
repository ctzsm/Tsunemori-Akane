#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			if (x > 0) sum += x;
		}
		printf("Case %d: %d\n", _, sum);
	}
	return 0;
}
