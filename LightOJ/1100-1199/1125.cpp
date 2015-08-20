#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, a[222], Q, D;
long long f[11][22];
void solve() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	while (Q--) {
		scanf("%d%d", &D, &M);
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			int x = (a[i] % D + D) % D;
			for (int j = M - 1; j >= 0; --j) {
				for (int k = 0; k < D; ++k) {
					f[j + 1][(k + x) % D] += f[j][k];
				}
			}
		}
		printf("%lld\n", f[M][0]);
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
