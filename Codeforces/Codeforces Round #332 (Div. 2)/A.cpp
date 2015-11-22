#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	int ans = min(a + b + c, (a + b) * 2);
	printf("%d\n", min(ans, (min(a, b) + c) * 2));
	return 0;
}
