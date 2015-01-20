#include <cstdio>

using namespace std;

long long f[40000];
int main() {
	freopen("in", "r", stdin);
	f[0] = 1;
	for (int j = 1; j <= 3; ++j) {
		for (int i = 1; i <= 32768; ++i) {
			if (i - j >= 0) f[i] += f[i - j];
		}
	}
	int n;
	while (~scanf("%d", &n)) {
		printf("%lld\n", f[n]);
	}
}