#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[205];
int n, sg[205];
bool f[50];
bool ok(int x) {
	if (s[x] == 'X') return false;
	if (x >= 2 && s[x - 2] == 'X' && s[x - 1] == 'X') return true;
	if (x >= 1 && s[x - 1] == 'X' && s[x + 1] == 'X') return true;
	if (s[x + 1] == 'X' && s[x + 2] == 'X') return true;
	s[x] = 'X';
	for (int i = 0; i < n - 2; ++i)
		if (s[i] == 'X' && s[i + 2] == 'X') { s[x] = '.'; return false; }
	for (int i = 0; i < n - 1; ++i)
		if (s[i] == 'X' && s[i + 1] == 'X') { s[x] = '.'; return false; }
	int res = 0, cnt = 0;
	for (int i = 0, f = 0; i < n; ++i) {
		if (s[i] == '.') {
			cnt ++;
		} else {
			if (f && cnt > 4)
				res ^= sg[cnt - 4];
			if (!f && cnt > 2)
				res ^= sg[cnt - 2];
			cnt = 0;
			f = 1;
		}
	}
	if (cnt > 2)
		res ^= sg[cnt - 2];
	s[x] = '.';
	return !res;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 0; i <= 200; ++i) {
		memset(f, false, sizeof f);
		for (int j = 1; j <= i; ++j) {
			int a = j - 3 >= 0 ? sg[j - 3] : 0;
			int b = i - j - 2 >= 0 ? sg[i - j - 2] : 0;
			f[a ^ b] = true;
		}
		for (int j = 0; ; ++j) if (!f[j]) {
			sg[i] = j; break;
		}
	}
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%s", s);
		n = strlen(s); s[n + 1] = 0;
		int cnt = 0;
		printf("Case %d:", _);
		for (int i = 0; i < n; ++i) if (ok(i)) {
			printf(" %d", i + 1); cnt ++;
		}
		if (!cnt) printf(" 0");
		printf("\n");
	}
	return 0;
}
