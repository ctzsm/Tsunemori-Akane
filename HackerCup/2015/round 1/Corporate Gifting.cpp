#include <sys/resource.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[200005];
long long dp[200005][30];
int n;
long long dfs(int u, int c) {
	if (dp[u][c] != -1)
		return dp[u][c];
	long long res = 0;
	for (int i = 0; i < (int)adj[u].size(); ++i) {
		int v = adj[u][i];
		long long cv = (n + 5) * 3;
		for (int j = 1; j <= 29; ++j) {
			if (j == c) continue;
			cv = min(cv, dfs(v, j));
		}
		res += cv;
	}
	return dp[u][c] = res + c;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if (x == 0) continue;
		adj[x].push_back(i);
	}
	memset(dp, -1, sizeof dp);
	long long ans = (n + 5) * 3;
	for (int i = 1; i <= 29; ++i)
		ans = min(ans, dfs(1, i));
	printf("%lld\n", ans);
}
int main() {
	const rlim_t kStackSize = 256 * 1024 * 1024;   // min stack size = 256 MB
	struct rlimit rl;
	int result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
		if (rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0) {
				fprintf(stderr, "setrlimit returned result = %d\n", result);
			}
		}
	}
	freopen("corporate_gifting.txt", "r", stdin);
	freopen("corporate_gifting.out", "w", stdout);
	// freopen("in", "r", stdin);
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
