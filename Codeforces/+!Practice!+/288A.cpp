#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

int n, k;
char s[1000005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	if (k > n || (n != 1 && k == 1)) {
		printf("-1\n");
		return 0;
	}
	s[n] = 0;
	for (int i = n - k, j = 0; i < n; ++i, ++j) {
		s[i] = 'a' + j;
	}
	for (int i = 0; i < n - k; ++i) {
		s[i] = 'a' + (i & 1);
	}
	if (n - k - 1 >= 0 && s[n - k - 1] == s[n - k]) std::swap(s[n - k], s[n - k + 1]);
	printf("%s\n", s);
	return 0;
}