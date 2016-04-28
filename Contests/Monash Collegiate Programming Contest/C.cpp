#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	p -= 1, n -= 1;
	int cnt = 0;
	while (true) {
		// printf("p = %d\n", p);
		if (p % k == 0) {
			printf("%d\n", cnt + p / k + 1);
			break;
		}
		// 0 1 2 / 3 4 5 / 6 7 8 / 9 10 11
		int r = (n + k) / k;
		cnt += r;
		// printf("%d\n", r);
		// printf("%d\n", p - p / k - 1);
		n -= r;
		p -= p / k + 1;
	}
	return 0;
}
