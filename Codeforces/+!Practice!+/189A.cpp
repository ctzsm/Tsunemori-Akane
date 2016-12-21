#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int n, a, b, c, ans = 0;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	for (int i = 0; i * a <= n; ++i) {
		for (int j = 0; i * a + j * b <= n; ++j) {
			int r = n - i * a - j * b;
			if (r % c == 0) {
				ans = max(ans, i + j + r / c);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
