#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

inline int calc(int x) {
	int res = 0;
	while (x) {
		res += x / 5;
		x /= 5;
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T, Q; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		scanf("%d", &Q);
		int l = 5, r = Q * 5;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (calc(mid) >= Q) r = mid;
			else l = mid + 1;
		}
		if (calc(l) == Q)
			printf("%d\n", l);
		else
			printf("impossible\n");
	}
	return 0;
}
