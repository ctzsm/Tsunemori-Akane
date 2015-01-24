#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int ans[11], tot = 0, N;
void dfs(int d, int ld, int row, int rd) {
	if (d == N) {
		tot ++;
		return;
	}
	int flag = ld | row | rd;
	for (int i = 0; i < N; ++i) {
		int mask = 1 << i;
		if (flag & mask) continue;
		dfs(d + 1, (ld | mask) >> 1, row | mask, (rd | mask) << 1);
	}
}
int main() {
	freopen("in", "r", stdin);
	memset(ans, -1, sizeof ans);
	while (true) {
		scanf("%d", &N);
		if (N == 0) break;
		if (ans[N] == -1) {
			tot = 0;
			dfs(0, 0, 0, 0);
			ans[N] = tot;
		}
		printf("%d\n", ans[N]);
	}
	return 0;
}