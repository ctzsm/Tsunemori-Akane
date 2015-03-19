#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, N, a[10005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		int m = *min_element(a, a + N);
		int ans = 1000 * 10000;
		for (int b = m - 5; b <= m; ++b) {
			int r = 0;
			for (int i = 0; i < N; ++i) {
				int k = a[i] - b;
				r += k / 5; k %= 5;
				r += k / 2; k %= 2;
				r += k;
			}
			ans = min(ans, r); 
		}
		printf("%d\n", ans);
	}
	return 0;
}
