#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
long long a[3];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		for (int i = 0; i < 3; ++i) scanf("%lld", &a[i]);
		sort(a, a + 3);
		printf("Case %d: ", _);
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
