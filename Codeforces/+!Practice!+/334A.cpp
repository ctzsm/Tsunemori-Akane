#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int a[105][105];
int main() {
	// freopen("in", "r", stdin);
	int n; scanf("%d", &n);
	int m = 1;
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; ++j)
			a[j][i] = m ++;
		for (int j = n - 1; j >= 0; --j)
			a[j][i + 1] = m ++;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
