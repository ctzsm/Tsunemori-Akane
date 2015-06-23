#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int a, b; scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", _, a + b);
	}
	return 0;
}
