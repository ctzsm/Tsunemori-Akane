#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005];
int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s);
	int n = strlen(s), cnt = 0, h = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') cnt ++;
		else cnt --;
		if (s[i] == '#') h ++;
		if (cnt < 0) {
			printf("-1\n");
			return 0;
		}
	}
	int th = h, tcnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') tcnt ++;
		else if (s[i] == '#') {
			if (th != 1)
				tcnt --, th --;
			else
				tcnt -= cnt + 1;
		} else tcnt --;
		if (tcnt < 0) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '#') {
			if (h != 1) {
				printf("%d\n", 1);
				h --;
			} else {
				printf("%d\n", cnt + 1);
			}
		}
	}
	return 0;
}
