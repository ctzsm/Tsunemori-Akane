#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, s, e, q[25];
char o[10];
char full[] = "The queue is full";
char empty[] = "The queue is empty";
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &m);
		s = e = 10;
		while (m--) {
			scanf("%s", o);
			if (o[4] == 'L') {
				int x; scanf("%d", &x);
				if (e - s < n) {
					q[s--] = x;
					printf("Pushed in left: %d\n", x);
				} else puts(full);
			} else if (o[4] == 'R') {
				int x; scanf("%d", &x);
				if (e - s < n) {
					q[++e] = x;
					printf("Pushed in right: %d\n", x);
				} else puts(full);
			} else if (o[4] == 'e') {
				if (s < e)
					printf("Popped from left: %d\n", q[++s]);
				else puts(empty);
			} else if (o[4] == 'i') {
				if (s < e)
					printf("Popped from right: %d\n", q[e--]);
				else puts(empty);
			}
		}
	}
	return 0;
}
