#include <cstdio>
#include <cstdlib>
#include <algorithm>

int n, m, f[1005];
int main() {
	int answer = 0x3fffffff;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) scanf("%d", &f[i]);
	std::sort(f, f + m);
	for (int i = 0; i < m - n + 1; ++i)
		answer = std::min(answer, f[i + n - 1] - f[i]);
	printf("%d\n", answer);
	return 0;
}