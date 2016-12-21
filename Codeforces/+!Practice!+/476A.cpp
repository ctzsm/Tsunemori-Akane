#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = n / 2; i >= 0; --i) {
		int s = n - 2 * i + i;
		if (s % m == 0) {
			printf("%d\n", s);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
