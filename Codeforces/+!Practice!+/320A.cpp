#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char s[15];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ) {
		if (i + 2 < len) {
			if (s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4') {
				i += 3;
				continue;
			}
		}
		if (i + 1 < len) {
			if (s[i] == '1' && s[i + 1] == '4') {
				i += 2;
				continue;
			}
		}
		if (s[i] == '1') {
			i += 1;
			continue;
		}
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}