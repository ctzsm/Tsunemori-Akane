#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	std::string sign, answer;
	long long x, l = -2000000000LL, h = 2000000000LL;
	bool el = true, eh = true;
	for (int i = 0; i < n; ++i) {
		std::cin >> sign >> x >> answer;
		if (answer == "N") {
			if (sign == ">=") sign = "<";
			else if (sign == "<=") sign = ">";
			else if (sign == ">") sign = "<=";
			else sign = ">=";
		}
		if (sign.size() == 1) {
			if (sign[0] == '>') {
				if (l <= x) l = x, el = false;
			} else {
				if (h >= x) h = x, eh = false;
			}
		} else {
			if (sign[0] == '>') {
				if (l < x) l = x, el = true;
			} else {
				if (h > x) h = x, eh = true;
			}
		}
	}
	if ((l == h && !(el && eh)) || l > h || (l == h - 1 && !el && !eh)) {
		std::cout << "Impossible\n" << std::endl;
	} else {
		std::cout << (el ? l : l + 1) << std::endl;
	}
	return 0;
}