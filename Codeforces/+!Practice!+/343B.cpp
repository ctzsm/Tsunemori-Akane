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

char s[100005];
int g(char c) {
	if (c == '+') return 1;
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int len = strlen(s);
	if (len & 1) {
		printf("No\n");
		return 0;
	}
	std::stack<std::pair<char, int> > stack;
	int cnt[2] = {0, 0};
	char cur = '+';
	for (int i = 0; i <= len; ++i) {
		if (cur != s[i]) {
			while (!stack.empty() && stack.top().first == cur) {
				cnt[g(cur)] += stack.top().second;
				stack.pop();
			}
			if (cnt[g(cur)] % 2 == 1) stack.push(std::make_pair(cur, 1));
			cur = s[i], cnt[g(s[i])] = 1;
		} else {
			cnt[g(cur)] ++;
		}
	}
	puts(stack.empty() ? "Yes" : "No");
	return 0;
}