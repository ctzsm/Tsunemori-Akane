#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char a[100005], b[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s%s", a, b);
	int len = strlen(a);
	int four = 0, seven = 0;
	for (int i = 0 ; i < len; ++i) {
		if (a[i] != b[i]) {
			if (a[i] == '4') four++;
			else seven ++;
		}
	}
	printf("%d\n", std::max(seven, four));
	return 0;
}