#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1005], t[2005];
void solve() {
	scanf("%s", s);
	int n = strlen(s), l = n, r = n;
	for (int i = 0; i < n; ++i) {
		if (i == 0) t[r++] = s[i];
		else {
			if (s[i] >= t[l]) t[--l] = s[i];
			else t[r++] = s[i];
		}
	}
	t[r++] = 0;
	printf("%s\n", t + l);
}
int main() {
	//freopen("in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
