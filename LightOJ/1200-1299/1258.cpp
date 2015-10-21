#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
char s[maxn], t[maxn];
int f[maxn];
int solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), ans = 0; t[n + 1] = 0;
	for (int i = 1; i <= n; ++i) t[n - i + 1] = s[i];
	f[1] = 0;
	for (int i = 2, j = 0; i <= n; ++i) {
		while (j && t[i] != t[j + 1]) j = f[j];
		if (t[i] == t[j + 1]) j++;
		f[i] = j;
	}
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j && s[i] != t[j + 1]) j = f[j];
		if (s[i] == t[j + 1]) j++;
		if (i == n) ans = j;
		if (j == n) j = f[j];
	}
	return n * 2 - ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
