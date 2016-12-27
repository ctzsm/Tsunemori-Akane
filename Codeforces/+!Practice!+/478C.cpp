#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long a[3];
int main() {
	// freopen("in", "r", stdin);
	for (int i = 0; i < 3; ++i)
		scanf("%lld", a + i);
	sort(a, a + 3);
	if (a[2] >= 2 * (a[1] + a[0]))
		printf("%lld\n", a[1] + a[0]);
	else
		printf("%lld\n", (a[2] + a[1] + a[0]) / 3);
	return 0;
}
