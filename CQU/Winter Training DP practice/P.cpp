#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, f[105][2];
char s[105];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		if (isupper(s[0])) f[0][0] = 2, f[0][1] = 2;
		else f[0][0] = 1, f[0][1] = 2;
		for (int i = 1; i < n; ++i) {
			if (isupper(s[i])) {
				f[i][0] = min(f[i - 1][0] + 2, f[i - 1][1] + 2);
				f[i][1] = min(f[i - 1][0] + 2, f[i - 1][1] + 1);
			} else {
				f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1] + 2);
				f[i][1] = min(f[i - 1][0] + 2, f[i - 1][1] + 2);
			}
		}
		printf("%d\n", min(f[n - 1][0], f[n - 1][1] + 1));
	}
	return 0;
}