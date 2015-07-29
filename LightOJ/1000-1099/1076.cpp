#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m, c[1005];
bool check(int x) {
	int now = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i] > x) return false;
		if (now + c[i] > x) {
			now = c[i], cnt++;
		} else now += c[i];
	}
	if (now) cnt++;
	return cnt <= m;
}
int solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	if (m >= n) return *max_element(c, c + n);
	int l = 0, r = accumulate(c, c + n, 0);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
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
