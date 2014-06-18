#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

int m, x, y;
int c[105];
bool in(int a) {
	return x <= a && a <= y;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &c[i]);
	scanf("%d%d", &x, &y);
	int sum = std::accumulate(c + 1, c + m + 1, 0);
	int beg = 0;
	for (int i = 0; i <= m; ++i) {
		beg += c[i];
		if (in(beg) && in(sum - beg)) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}