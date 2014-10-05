#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T, R, C, r, c;
char G[1005][1005], P[1005][1005];
void solve() {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; ++i) scanf("%s", G[i]);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) scanf("%s", P[i]);
	for (int i = 0; i <= R - r; ++i) {
		for (int j = 0; j <= C - c; ++j) {
			for (int a = 0; a < r; ++a) {
				for (int b = 0; b < c; ++b) {
					if (G[i+a][j+b] != P[a][b]) 
						goto label1;
				}
			}
			printf("YES\n");
			return;
			label1:;
		}
	}
	printf("NO\n");
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}