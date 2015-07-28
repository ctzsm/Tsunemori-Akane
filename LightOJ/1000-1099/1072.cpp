#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
double R;
double solve() {
	scanf("%lf%d", &R, &n);
	double x = sin(M_PI / n);
	return R * x / (1 + x);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
