#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
long long n;
int solve() {
	scanf("%lld", &n);
	vector<int> v;
	while (n) {
		v.push_back(n % 2);
		n /= 2;
	}
	v.push_back(0);
	reverse(v.begin(), v.end());
	next_permutation(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		n = (n << 1) | v[i];
	return n;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
