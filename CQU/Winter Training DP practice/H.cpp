#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int N, a[1005];
long long f[1005];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &N), N) {
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < N; ++i) {
			f[i] = a[i];
			for (int j = 0; j < i; ++j)
				if (a[i] > a[j])
					f[i] = max(f[i], f[j] + a[i]);
		}
		long long ans = 0;
		for (int i = 0; i < N; ++i) ans = max(ans, f[i]);
		cout << ans << endl;
	}
	return 0;
}