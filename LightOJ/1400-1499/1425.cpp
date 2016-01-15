#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, r[100005];
bool check(int k) {
	int now = 0;
	for (int i = 0; i < n; ++i) {
		if (k < r[i] - now) return false;
		else if (k == r[i] - now) k --;
		now = r[i];
	}
	return true;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", r + i);
	int l = 0, h = r[n - 1];
	while (l < h) {
		int m = (l + h) >> 1;
		if (check(m))
			h = m;
		else
			l = m + 1;
	}
	return l;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
