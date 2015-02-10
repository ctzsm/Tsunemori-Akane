#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int N, M, h[1005][1005];
char b[1005][1005];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &N, &M)) {
		for (int i = 0; i < N; ++i) scanf("%s", b[i]);
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
			h[i][j] = b[i][j] - '0';
		for (int i = 1; i < N; ++i)	for (int j = 0; j < M; ++j)
			if (h[i][j])
				h[i][j] += h[i - 1][j];
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			sort(h[i], h[i] + M, greater<int>());
			for (int j = 0; j < M; ++j)
				ans = max(ans, h[i][j] * (j + 1));
		}
		printf("%d\n", ans);
	}
	return 0;
}