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

int T;
long long L, R;
char num[200];
bool test(long long x) {
	if (x < 10) return true;
	sprintf(num, "%lld", x);
	int len = strlen(num);
	if (x % len != 0) return false;
	return test(x / len);
}
bool test2(long long x, int l) {
	sprintf(num, "%lld", x);
	int len = strlen(num);
	return len == l;
}
void brute() {
	int res = 0;
	for (int i = L; i <= R; ++i) {
		res += test(i);
	}
	printf("%d\n", res);
}
int getLen(long long x) {
	char num[20];
	sprintf(num, "%lld", x);
	return strlen(num);
}
std::vector<long long> v;
char n[20];
void init() {
	for (int i = 0; i < 10; ++i) v.push_back(i);
	int len = 0, upper = 10;
	while (upper - len > 0) {
		for (int i = len; i < upper; ++i) {
			int l = getLen(v[i]);
			for (int j = std::max(l, 2); j <= 18; ++j) {
				if (test2(v[i] * j, j)) {
					v.push_back(v[i] * j);
				}
			}
		}
		len = upper;
		upper = (int)v.size();
	}
	std::sort(v.begin(), v.end());
}
void solve() {
	int x = (int)(std::upper_bound(v.begin(), v.end(), L - 1) - v.begin());
	int y = (int)(std::upper_bound(v.begin(), v.end(), R) - v.begin());
	printf("%d\n", y - x);
}
int main() {
	freopen("in", "r", stdin);
	init();
	for (int i = 0; i < (int)v.size(); ++i)
		if (!test(v[i]))
			printf("%lld\n", v[i]);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &L, &R);
		solve();
	}
	return 0;
}