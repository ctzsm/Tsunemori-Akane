#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const char answer[2][5] = {
	"No", "Yes"
};
char s[105];
int cnt[2][26];
int solve() {
	memset(cnt, 0, sizeof cnt);
	for (int k = 0; k < 2; ++k) {
		gets(s);
		int l = strlen(s);
		for (int i = 0; i < l; ++i) {
			if (isalpha(s[i]))
				cnt[k][tolower(s[i]) - 'a'] ++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[0][i] != cnt[1][i])
			return false;
	}
	return true;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T); gets(s);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, answer[solve()]);
	return 0;
}
