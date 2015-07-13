#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
char s[1005];
bool p[1005][1005];
int f[1005];
int solve() {
	scanf("%s", s);
	int n = strlen(s);
	memset(p, false, sizeof p);
	for (int i = 0; i < n; ++i) p[i][i] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 1; i - j >= 0 && i + j < n; ++j)
			if (s[i - j] == s[i + j])
				p[i - j][i + j] = true;
			else break;
	for (int i = 1; i < n; ++i)
		for (int j = 0; i - j - 1 >= 0 && i + j < n; ++j)
			if (s[i - j - 1] == s[i + j])
				p[i - j - 1][i + j] = true;
			else break;
	f[0] = 0;
	for (int i = 0; i < n; ++i) {
		f[i + 1] = f[i] + 1;
		for (int j = 0; j < i; ++j) {
			if (p[j][i])
				f[i + 1] = min(f[i + 1], f[j] + 1);
		}
	}
	return f[n];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
