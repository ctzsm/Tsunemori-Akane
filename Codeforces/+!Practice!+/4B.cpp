#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int d, tot, minT[35], maxT[35];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &d, &tot);
	for (int i = 1; i <= d; ++i) scanf("%d%d", &minT[i], &maxT[i]);
	int minS = std::accumulate(minT + 1, minT + d + 1, 0);
	int maxS = std::accumulate(maxT + 1, maxT + d + 1, 0);
	if (!(minS <= tot && tot <= maxS)) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	tot -= minS;
	for (int i = 1; i <= d; ++i) {
		printf("%d ", minT[i] + std::min(maxT[i] - minT[i], tot));
		tot -= std::min(maxT[i] - minT[i], tot);
	}
	return 0;
}