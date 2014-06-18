#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, a[105];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}