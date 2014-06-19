#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

char s[1000005];
std::deque<int> q;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s);
	q.push_back(n);
	for (int i = n - 2; i >= 0; --i) {
		if (s[i] == 'l') q.push_back(i + 1);
		else q.push_front(i + 1);
	}
	while(!q.empty()) {
		printf("%d\n", q.front());
		q.pop_front();
	}
	return 0;
}