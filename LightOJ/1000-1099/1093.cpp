#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, d, a[100005];
int solve() {
	scanf("%d%d", &n, &d);
	deque<int> q1, q2;
	int ans = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) {
		while (!q1.empty() && a[q1.back()] < a[i]) q1.pop_back();
		while (!q2.empty() && a[q2.back()] > a[i]) q2.pop_back();
		q1.push_back(i);
		q2.push_back(i);
		ans = max(ans, a[q1.front()] - a[q2.front()]);
		if (i - q1.front() + 1 >= d) q1.pop_front();
		if (i - q2.front() + 1 >= d) q2.pop_front();
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