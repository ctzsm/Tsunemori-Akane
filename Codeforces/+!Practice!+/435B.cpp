#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

char a[20], b[20];
int len, k;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s%d", a, &k);
	len = strlen(a);
	for (int i = 0; i < len; ++i) {
		int d = i;
		for (int j = i + 1; j < len; ++j) {
			if (j - i > k) break;
			if (a[d] < a[j]) {
				d = j;
			}
		}
		if (d != i) {
			char c = a[d];
			for (int j = d; j > i; --j) a[j] = a[j - 1];
			a[i] = c, k -= d - i;
		}
	}
	printf("%s\n", a);
	return 0;
}