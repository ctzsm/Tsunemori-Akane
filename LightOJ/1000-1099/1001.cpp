#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		int a = min(n, 10);
		printf("%d %d\n", a, n - a);
	}
	return 0;
}
