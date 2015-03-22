#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, cnt[26][2];
char s[10004];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		if (n & 1) {
			printf("-1\n");
			continue;
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
			cnt[s[i] - 'a'][i < n / 2] ++;
		int ans = 0;
		for (int i = 0; i < 26; ++i)
			ans += abs(cnt[i][0] - cnt[i][1]);
		printf("%d\n", ans / 2);
	}
	return 0;
}
