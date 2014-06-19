#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n, m;
int table[55][55];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			scanf("%d", &table[i][j]);
	for (int i = 0; i < n; ++i)
		if (table[i][0] || table[i][m - 1]) {
			printf("2\n");
			return 0;
		}
	for (int j = 0; j < m; ++j)
		if (table[0][j] || table[n - 1][j]) {
			printf("2\n");
			return 0;
		}
	printf("4\n");
	return 0;

}