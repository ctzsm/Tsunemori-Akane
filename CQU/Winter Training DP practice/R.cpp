#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int M, N, a[200005], f[200005], w[200005];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &M, &N)) {
		for (int i = 0, ni = 0; i < M; ++i, ni += N)
			for (int j = 0; j < N; ++j) 
				scanf("%d", &a[ni + j]);
		for (int i = 0, ni = 0; i < M; ++i, ni += N) {
			f[0] = a[ni];
			for (int j = 1; j < N; ++j) {
				f[j] = f[j - 1];
				if (j - 2 >= 0) f[j] = max(f[j], f[j - 2] + a[ni + j]);
				else f[j] = max(f[j], a[ni + j]);
			}
			w[i] = f[N - 1];
		}
		f[0] = w[0];
		for (int i = 1; i < M; ++i) {
			f[i] = f[i - 1];
			if (i - 2 >= 0) f[i] = max(f[i], f[i - 2] + w[i]);
			else f[i] = max(f[i], w[i]);
		}
		printf("%d\n", f[M - 1]);
	}
	return 0;
}