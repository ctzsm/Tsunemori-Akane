#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n;
double f[105];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", &f[i]);
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 1; j < 7 && i + j < n; ++j)
				f[i] += f[i + j] / min(6, n - i - 1);
		}
		printf("Case %d: %.7f\n", _, f[0]);
	}
	return 0;
}
