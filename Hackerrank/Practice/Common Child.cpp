#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[5005], t[5005];
int f[2][5005];
int main() {
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	for (int i = 1, pre = 0, now = 1; i <= n; ++i, swap(pre, now)) {
		for (int j = 1; j <= m; ++j) 
			if (s[i - 1] == t[j - 1]) f[now][j] = f[pre][j - 1] + 1;
			else f[now][j] = max(f[pre][j], f[now][j - 1]);
	}
	printf("%d\n", f[n % 2][m]);
	return 0;
}
