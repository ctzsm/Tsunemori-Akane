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

char s[100005], t[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s), j = 0;
	char now = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] >= now) {
			t[j++] = s[i];
			now = s[i];
		}
	}
	std::reverse(t, t + j);
	t[j] = 0;
	printf("%s\n", t);
	return 0;
}