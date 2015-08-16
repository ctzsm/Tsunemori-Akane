#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long N, M, a[16];
int solve() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < M; ++i) scanf("%lld", &a[i]);
	sort(a, a + M);
	for (int i = 0; i < M; ++i) {
		if (a[i] > N) {
			M = i;
			break;
		}
	}
	int L = 1 << M;
	long long ans = 0;
	for (int i = 1; i < L; ++i) {
		long long lcm = 1, cnt = 0;
		for (int j = 0; j < M; ++j) {
			if (i & (1 << j)) {
				lcm = lcm * a[j] / __gcd(lcm, a[j]);
				if (lcm > N) break;
				cnt ++;
			}
		}
		if (lcm > N) continue;
		if (cnt & 1) ans += N / lcm;
		else ans -= N / lcm;
	}
	return N - ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
