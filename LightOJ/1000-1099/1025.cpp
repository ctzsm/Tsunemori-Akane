#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
char s[65];
long long f[65][65];
long long solve() {
	scanf("%s", s);
	int n = strlen(s);
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i) f[i][i] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (s[i] == s[j])
				f[i][j] = 1;
	for (int l = 1; l <= n; ++l) {
		for (int i = 0, j = l - 1; j < n; ++i, ++j) {
			for (int a = 0; a < i; ++a)
				for (int b = j + 1; b < n; ++b)
					if (s[a] == s[b])
						f[a][b] += f[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			ans += f[i][j];
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
