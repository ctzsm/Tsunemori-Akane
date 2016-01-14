#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[105], s[105], f[105][105];
int total(int i, int j) {
	if (i <= 0) i += n;
	if (j > n) j -= n;
	if (i < j)
		return s[n] - (s[j - 1] - s[i]);
	else
		return s[i] - s[j - 1];
}
int dfs(int i, int j) {
	if (i <= 0) i += n;
	if (j > n) j -= n;
	if (~f[i][j]) return f[i][j];
	if (i == j) return f[i][j] = a[i];
	int l = a[i] + total(i - 1, j) - dfs(i - 1, j);
	int r = a[j] + total(i, j + 1) - dfs(i, j + 1);
	return f[i][j] = max(l, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) a[i] %= 2;
	if (n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	if (n == 2) {
		printf("%d\n", a[1] + a[2] == 1);
		return 0;
	}
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	memset(f, -1, sizeof f);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int zvonko = dfs(i - 1, i + 1);
		if (s[n] - zvonko > zvonko)
			ans ++;
	}
	printf("%d\n", ans);
	return 0;
}
