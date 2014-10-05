#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int main() {
	freopen("in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 20 + 1;
	printf("%d %d\n", n, rand() % (n + 1));
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", rand() % 1000000, rand() % 1000000);
	}
	return 0;
}