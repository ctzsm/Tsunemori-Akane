#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

char s[1005];
int cnt[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i) cnt[s[i] - 'a'] ++;
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) ans ++;
	}
	if (std::max(0, ans - 1) & 1) {
		puts("Second");
	} else {
		puts("First");
	}
	return 0;
}