#include <ext/rope>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

char o[2];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		int n, m, x;
		scanf("%d%d", &n, &m);
		rope<int> a;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			a.push_back(x);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%s%d", o, &x);
			if (o[0] == 'a') {
				a.push_back(x);
			} else {
				if (x > a.size())
					printf("none\n");
				else {
					printf("%d\n", a[x - 1]);
					a.erase(x - 1, 1);
				}
			}
		}
	}
	return 0;
}
