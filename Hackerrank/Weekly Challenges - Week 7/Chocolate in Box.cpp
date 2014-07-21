#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int N, A[1000005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	int SG = 0;
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	for (int i = 0; i < N; ++i) SG ^= A[i];
	if (!SG) {
		printf("0\n");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int cur = SG ^ A[i];
		if (A[i] >= cur) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}