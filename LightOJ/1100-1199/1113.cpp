#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const char init[] = "http://www.lightoj.com/";
char com[10];
char url[105][55];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		memcpy(url[0], init, sizeof init);
		scanf("%s", com);
		int p = 0, m = 0;
		while (com[0] != 'Q') {
			if (com[0] == 'V') {
				m = ++p;
				scanf("%s", url[p]);
				printf("%s\n", url[p]);
			} else if (com[0] == 'B') {
				if (p) {
					printf("%s\n", url[--p]);
				} else {
					printf("Ignored\n");
				}
			} else if (com[0] == 'F') {
				if (p < m) {
					printf("%s\n", url[++p]);
				} else {
					printf("Ignored\n");
				}
			}
			scanf("%s", com);
		}
	}
	return 0;
}
