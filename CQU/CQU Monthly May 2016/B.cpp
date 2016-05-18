#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		printf("%d\n", __builtin_popcount(n));
	}
	return 0;
}
