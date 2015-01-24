#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[5005], t[5005];
int f[5005][5005];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%s%s", s, t)) {
		int n = strlen(s), m = strlen(t);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) 
				if (s[i - 1] == t[j - 1])
					f[i][j] = f[i - 1][j - 1] + 1;
				else
					f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		printf("%d\n", f[n][m]);
	}
	return 0;
}