#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
char s[65];
long long f[65][65];
long long dfs(int l, int r) {
	if (l > r) return 0;
	if (f[l][r] != -1) return f[l][r];
	if (l == r) return f[l][r] = 1;
	if (s[l] == s[r])
		return f[l][r] = dfs(l + 1, r) + dfs(l, r - 1) + 1;
	else
		return f[l][r] = dfs(l + 1, r) + dfs(l, r - 1) - dfs(l + 1, r - 1);
}
long long solve() {
	scanf("%s", s);
	int n = strlen(s);
	memset(f, -1, sizeof f);
	return dfs(0, n - 1);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
