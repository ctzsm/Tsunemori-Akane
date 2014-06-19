#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
char board[105][105];

inline bool in(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n && board[i][j] == '#';
}
bool check(int i, int j) {
	if (in(i + 1, j - 1) && in(i + 1, j) && in(i + 1, j + 1) && in(i + 2, j)) {
		board[i + 1][j - 1] = board[i + 1][j] = '.';
		board[i + 1][j + 1] = board[i + 2][j] = '.';
		board[i][j] = '.';
		return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", board[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '#' && !check(i, j)) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}