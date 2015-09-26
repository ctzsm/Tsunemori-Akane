#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[205];
long long b;
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%s%lld", s, &b); b = llabs(b);
		int n = strlen(s);
		long long r = 0;
		for (int i = 0; i < n; ++i) {
			if (!isdigit(s[i])) continue;
			r = (r * 10 + s[i] - '0') % b;
		}
		printf("Case %d: %s\n", _, r ? "not divisible" : "divisible");
	}
	return 0;
}
