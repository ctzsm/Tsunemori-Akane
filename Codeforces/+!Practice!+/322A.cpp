#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	int i = 1, j = 1, cnt = 0;
	while (true) {
		cnt ++;		
		if (i == n && j == m) break;
		if (i == n || (i == j && j < m)) j ++;
		else i ++;
	}
	printf("%d\n", cnt);
	i = j = 1;
	while (true) {
		printf("%d %d\n", i, j);		
		if (i == n && j == m) break;
		if (i == n || (i == j && j < m)) j ++;
		else i ++;
	}
	return 0;
}