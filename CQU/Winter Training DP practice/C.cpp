#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int N, a[10005];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &N), N) {
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		bool flag = true;
		for (int i = 0; i < N; ++i) if (a[i] >= 0) flag = false;
		if (flag) {
			printf("0 %d %d\n", a[0], a[N - 1]);
			continue;
		}
		int ans = -1, l = a[0], r = a[0], sum = 0, t = a[0];
		for (int i = 0; i < N; ++i) {
			if (sum + a[i] < 0) {
				sum = 0, t = a[i + 1];
			} else {
				sum += a[i];
				if (ans < sum) {
					ans = sum, l = t, r = a[i];
				}
			}
		}
		printf("%d %d %d\n", ans, l, r);
	}
	return 0;
}