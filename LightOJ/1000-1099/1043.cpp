#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
double ab, ac, bc, ratio;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%lf%lf%lf%lf", &ab, &ac, &bc, &ratio);
		printf("Case %d: %.8f\n", _, sqrt(ratio / (ratio + 1)) * ab);
	}
	return 0;
}
