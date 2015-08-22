#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a[100005];
inline long long calc(int x) {
	return 1LL * x * (x - 1) / 2;
}
long long solve() {
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof a);
	int s = 0, x; a[0] = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		s = (s + x) % m;
		a[s] ++;
	}
	long long ans = 0;
	for (int i = 0; i < m; ++i) 
		ans += calc(a[i]);
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}