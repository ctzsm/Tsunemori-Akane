#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m;
set<int> dict;
int a[100005], b[100005];
int main(void) {
//	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (dict.find(a[i]) == dict.end()) {
			cnt++;
			dict.insert(a[i]);
		}
		b[i] = cnt;
	}
	for (int i = 0; i < m; ++i) {
		int x; scanf("%d", &x);
		printf("%d\n", b[x - 1]);
	}
	return 0;
}