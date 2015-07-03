#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, k;
char s[27];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) s[i] = i + 'A';
		s[n] = 0;
		do {
			printf("%s\n", s);
			k--;
		} while (next_permutation(s, s + n) && k);
	}
	return 0;
}
