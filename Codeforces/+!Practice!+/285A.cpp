#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, k;
int a[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) a[i] = n - i;
	std::sort(a + k, a + n);
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}