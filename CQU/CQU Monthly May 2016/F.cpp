#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[1000005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		int n; scanf("%d", &n);
		bool flag = true;
		set<int> s;
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 0; i < n; ++i) {
			int x = a[i] - i;
			if (s.find(x) == s.end()) s.insert(x);
			else {
				flag = false;
				break;
			}
		}
		puts(flag ? "Yes" : "No");
	}
	return 0;
}
