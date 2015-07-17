#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const char ANS[3][6] = {"GOOD", "BAD", "MIXED"};
int T;
bool f[55][6][2];
bool vowel(char x) {
	if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
		return true;
	return false;
}
char s[55];
int solve() {
	scanf("%s", s);
	int n = strlen(s), ans = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '?') continue;
		s[i] = vowel(s[i]) ? '1' : '0';
	}
	memset(f, false, sizeof f);
	if (s[0] == '?' || s[0] == '0') f[1][1][0] = true;
	if (s[0] == '?' || s[0] == '1') f[1][1][1] = true;
	for (int i = 1; s[i]; ++i) {
		if (s[i] == '?' || s[i] == '1') {
			for (int j = 1; j < 5; ++j) {
				if (f[i][j][0]) {
					f[i + 1][1][1] = true;
					break;
				}
			}
			for (int j = 1; j < 3; ++j) {
				if (f[i][j][1]) {
					if (j + 1 == 3) ans |= 2;
					f[i + 1][j + 1][1] = true;
				}
			}
		}
		if (s[i] == '?' || s[i] == '0') {
			for (int j = 1; j < 3; ++j) {
				if (f[i][j][1]) {
					f[i + 1][1][0] = true;
					break;
				}
			}
			for (int j = 1; j < 5; ++j) {
				if (f[i][j][0]) {
					if (j + 1 == 5) ans |= 2;
					f[i + 1][j + 1][0] = true;
				}
			}
		}
	}
	for (int i = 1; i < 5; ++i) if (f[n][i][0]) ans |= 1;
	for (int i = 1; i < 3; ++i) if (f[n][i][1]) ans |= 1;
	return ans - 1;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, ANS[solve()]);
	return 0;
}
