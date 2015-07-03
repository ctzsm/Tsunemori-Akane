#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		double r; scanf("%lf", &r);
		printf("Case %d: %.2f\n", _, r * r * (4 - M_PI));
	}
	return 0;
}
