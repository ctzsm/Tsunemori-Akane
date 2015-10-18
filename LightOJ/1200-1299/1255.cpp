#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
char s[maxn], t[maxn];
int f[maxn];
int KMP() {
	int n = strlen(s), m = strlen(t), ans = 0;
	f[0] = -1;
	for (int i = 1, j = -1; i < m; ++i) {
		while (j >= 0 && t[i] != t[j + 1]) j = f[j];
		if (t[j + 1] == t[i]) j++;
		f[i] = j;
	}
	for (int i = 0, j = -1; i < n; ++i) {
		while (j >= 0 && s[i] != t[j + 1]) j = f[j];
		if (s[i] == t[j + 1]) j++;
		if (j == m - 1) {
			ans ++;
			j = f[j];
		}
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%s%s", s, t);
		printf("Case %d: %d\n", _, KMP());
	}
	return 0;
}
