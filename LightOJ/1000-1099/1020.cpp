#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const char A[] = "Alice", B[] = "Bob";
int T, n;
char s[10];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%s", &n, s);
		printf("Case %d: ", _);
		if (s[0] == 'A') {
			puts(n % 3 == 1 ? B : A);
		} else {
			puts(n % 3 == 0 ? A : B);
		}
	}
	return 0;
}
