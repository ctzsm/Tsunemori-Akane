#include <bits/stdc++.h>

using namespace std;

char s[100005];
int cnt[26];
int main() {
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i) cnt[s[i] - 'a'] ++;
	int odd = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) odd ++;
	}
	if (odd > 1) printf("NO\n");
	else printf("YES\n");
	return 0;
}