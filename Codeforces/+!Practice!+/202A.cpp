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

std::string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	std::cin >> s;
	std::sort(s.begin(), s.end(), std::greater<char>());
	char c = s[0];
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != c) {
			std::cout << s.substr(0, i) << std::endl;
			return 0;
		}
	std::cout << s << std::endl;
	return 0;
}