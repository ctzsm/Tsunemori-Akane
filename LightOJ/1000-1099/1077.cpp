#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long ax, ay, bx, by;
long long solve() {
	scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
	return __gcd(abs(ax - bx), abs(ay - by)) + 1;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
