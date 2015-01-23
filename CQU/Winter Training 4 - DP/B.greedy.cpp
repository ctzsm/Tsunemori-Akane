#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[500005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d%s", &n, &k, s);
	int ans = n;
	if (k == 2) {
		int x = 0;
		for (int j = 0; j < 2; ++j) {
			int cnt = 0;
			for (int i = 0; i < n; ++i)
				if (s[i] - 'A' != (i + j) % 2) cnt++;
			if (ans > cnt) {
				ans = cnt, x = j;
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < n; ++i) putchar((i + x) % 2 + 'A'); printf("\n");
		return 0;
	}
	ans = 0;
	for (int i = 1; i < n; ++i)
		if (s[i] == s[i - 1]) {
			for (int j = 'A'; j < 'A' + k; ++j)
				if (s[i - 1] != j && s[i + 1] != j) {
					s[i]= j; break;
				}
			ans ++;
		}
	printf("%d\n%s\n", ans, s);
	return 0;
}