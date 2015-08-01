#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[30005];
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int ans = 0;
	a[0] = a[n + 1] = 0;
	stack<int> s; s.push(0);
	for (int i = 1; i <= n + 1; ++i) {
		while (a[s.top()] > a[i]) {
			int l = s.top(); s.pop();
			ans = max(ans, a[l] * (i - s.top() - 1));
		}
		s.push(i);
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
