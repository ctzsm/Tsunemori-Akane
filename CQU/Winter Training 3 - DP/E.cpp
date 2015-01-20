#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[10005];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &n), n) {
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] >= 0) flag = false;
		}
		if (flag) {
			printf("0 %d %d\n", a[0], a[n - 1]);
			continue;
		}
		int sum = 0, ans = -1, ans1 = a[0], ans2 = a[0], x = a[0];
		for (int i = 0; i < n; ++i) {
			if (sum + a[i] < 0) {
				sum = 0;
			} else {
				if (sum == 0) x = a[i];
				sum += a[i];
				if (ans < sum) {
					ans = sum;
					ans1 = x, ans2 = a[i];
				}
			}
		}
		printf("%d %d %d\n", ans, ans1, ans2);
	}
	return 0;
}