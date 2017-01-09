#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a[5005], f[5005];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		double d; scanf("%d%lf", a + i, &d);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		f[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[i] >= a[j])
				f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
	}
	printf("%d\n", n - ans);
	return 0;
}
