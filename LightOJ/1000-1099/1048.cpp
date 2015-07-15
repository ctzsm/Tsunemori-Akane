#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, k, n, a[1005];
bool check(int x) {
	int now = 0, cnt = 1;
	for (int i = 0; i <= n; ++i) {
		if (now + a[i] <= x) {
			now += a[i];
		} else {
			now = a[i], cnt ++;
		}
	}
	return cnt <= k + 1;
}
void calc(int x) {
	stack<int> s;
	for (int i = n; i >= 0; --i) s.push(a[i]);
	int i = 0;
	while (s.size() + i > k + 1) {
		int a = s.top(); s.pop();
		int b = s.top(); s.pop();
		if (a + b <= x) s.push(a + b);
		else {
			i++; printf("%d\n", a);
			s.push(b);
		}
	}
	while (!s.empty()) {
		printf("%d\n", s.top());
		s.pop();
	}
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);
	int l = *max_element(a, a + n + 1);
	int r = accumulate(a, a + n + 1, 0);
	while (l < r) {
		int m = (l + r) >> 1;
		if (check(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
	calc(l);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
