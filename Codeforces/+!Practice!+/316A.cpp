#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

char s[100005];
int cnt[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int len = strlen(s);
	int question = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '?') question ++;
		else if (std::isalpha(s[i])) {
			cnt[s[i] - 'A'] ++;
		}
	}
	long long ans = 1, x = 10;
	for (int i = 0; i < 26; ++i) if (cnt[i]) {
		ans *= x; x--;
	}
	if (s[0] == '?') ans *= 9, question --;
	if (std::isalpha(s[0])) {
		ans /= 10; ans *= 9;
	}
	std::cout << ans;
	for (int i = 0; i < question; ++i) std::cout << '0';
	return 0;
}