#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
char room[105][105];
bool visited[105][105];
int ans[105][2];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", room[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) 
			if (room[i][j] == '.') {
				for (int k = 1; k <= n; ++k)
					visited[i][k] = visited[k][j] = true;
			}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (!visited[i][j]) {
				printf("-1\n");
				return 0;
			}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (room[i][j] == '.') {
				ans[cnt][0] = i;
				ans[cnt++][1] = j;
				break;
			}
		}
	}
	if (cnt == n) {
		goto output;
	}
	cnt = 0;
	for (int j = 1; j <= n; ++j) 
		for (int i = 1; i <= n; ++i) {
			if (room[i][j] == '.') {
				ans[cnt][0] = i;
				ans[cnt++][1] = j;
				break;
			}
		}
output:
	for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}