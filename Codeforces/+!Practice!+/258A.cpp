#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char a[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", a);
	int len = strlen(a);
	bool flag = false;
	for (int i = 0; i < len; ++i) {
		if (!flag && a[i] == '0') {
			flag = true;
			continue;
		}
		if (!flag && i == len - 1) continue;
		printf("%c", a[i]);
	}
	return 0;
}