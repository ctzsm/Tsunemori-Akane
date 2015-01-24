#include <cstdio>
#include <algorithm>

using namespace std;

int N, f[105][105];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) scanf("%d", &f[i][j]);
	}
	for (int i = N - 2; i >= 0; --i) 
		for (int j = 0; j <= i; ++j)
			f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
	printf("%d\n", f[0][0]);
	return 0;
}