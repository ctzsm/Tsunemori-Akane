#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s), cnt[3] = {0, 0, 0};
		for (int i = 0; i < n; ++i) {
			char c = tolower(s[i]);
			if (c == 'a') cnt[0] ++;
			if (c == 'c' && cnt[0]) {
				cnt[0] --, cnt[1] ++;
			}
			if (c == 'm' && cnt[1]) {
				cnt[1] --, cnt[2] ++;
			}
		}
		printf("%d\n", cnt[2]);
	}
	return 0;
}
