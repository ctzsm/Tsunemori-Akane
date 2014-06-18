#include <cstdio>
#include <algorithm>
#include <functional>

int k, a[15];
int main() {
	scanf("%d", &k);
	for (int i = 0; i < 12; ++i) scanf("%d", &a[i]);
	std::sort(a, a + 12, std::greater<int>());
	int sum = 0;
	for (int i = 0; i < 12; ++i) {
		if (sum >= k) {
			printf("%d\n", i);
			return 0;
		}
		sum += a[i];
	}
	if (sum >= k) printf("12\n");
	else printf("-1\n");
	return 0;
}