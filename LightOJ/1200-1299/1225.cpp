#include <cstdio>
#include <cstring>

char s[12];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%s", s);
		int n = strlen(s), flag = 1;
		for (int i = 0, j = n - 1; i < j; ++i, --j)
			if (s[i] != s[j]) { flag = 0; break; }
		printf("Case %d: %s\n", _, flag ? "Yes" : "No");
	}
	return 0;
}
