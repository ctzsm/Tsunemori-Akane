#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[105];
bool visited[105];
int solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	memset(visited, false, sizeof visited);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (visited[a[i]]) continue;
		int x = a[i], cnt = 0;
		do {
			visited[x] = true;
			x = a[x];
			cnt ++;
		} while (x != a[i]);
		ans += cnt - 1;
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
