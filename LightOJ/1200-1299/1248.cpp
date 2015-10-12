#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

double f[100005];
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 100001; ++i) f[i] = f[i - 1] + 1.0 / i;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		printf("Case %d: %.10f\n", _, f[n - 1] * n + 1.0);
	}
	return 0;
}
