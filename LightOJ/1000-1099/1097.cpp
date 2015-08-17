#include <ext/rope>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

const int l = 1429431;
rope<int> a;
void init() {
	a.push_back(0);
	for (int i = 1; i <= l; i += 2) a.push_back(i);
	for (int i = 2; i < a.size(); ++i) {
		int x = a[i];
		for (int j = a.size() / x * x; j > 0; j -= x)
			a.erase(j, 1);	
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		printf("Case %d: %d\n", _, a[n]);
	}
 	return 0;
}
