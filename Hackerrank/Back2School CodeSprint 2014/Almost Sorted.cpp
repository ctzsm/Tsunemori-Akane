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

using namespace std;

int n, d[100005];
bool sorted() {
	bool flag = true;
	for (int i = 1; i < n; ++i)
		if (d[i] < d[i - 1]) {
			flag = false;
			break;
		}
	return flag;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
	if (n <= 1 && sorted()) {
		printf("yes\n");
		return 0;
	}
	int l = 0, h = n - 1;
	for (int i = 0; i < n - 1; ++i) {
		if (d[i] > d[i + 1]) {
			l = i;
			break;
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		if (d[i] < d[i - 1]) {
			h = i;
			break;
		}
	}
	swap(d[l], d[h]);
	if (sorted()) {
		printf("yes\nswap %d %d\n", l + 1, h + 1);
		return 0;
	}
	swap(d[l], d[h]);
	for (int i = l, j = h; i < j; ++i, --j) swap(d[i], d[j]);
	if (sorted()) {
		printf("yes\nreverse %d %d\n", l + 1, h + 1);
		return 0;
	}
	printf("no\n");
	return 0;
}