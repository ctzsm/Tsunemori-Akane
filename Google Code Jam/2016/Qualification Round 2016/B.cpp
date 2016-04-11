#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[105];
int t[105], n;
int dfs(int i) {
	if (i == 0) {
		if (!t[i]) return t[i] ^= 1;
		return 0;
	};
	int res = 0;
	if (!t[i]) {
		for (int j = 0; j < i; ++j) t[j] ^= 1;
	}
	res += dfs(i - 1);
	if (!t[i]) {
		t[i] = 1;
		reverse(t, t + i + 1);
		res += 1;
	}
	return res;
}
int solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) t[i] = s[i] == '+';
	n = unique(t, t + n) - t;
	return dfs(n - 1);
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: %d\n", _, solve());
		// for (int i = 0; i < n; ++i)
		// 	putchar(t[i] ? '+' : '-');
		// putchar('\n');
	}
	return 0;
}
