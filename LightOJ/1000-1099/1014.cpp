#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, P, L;
void solve() {
	scanf("%d%d", &P, &L);
	if (P - L <= L) {
		printf(" impossible\n");
		return;
	}
	vector<int> ans;
	P -= L;
	int sP = sqrt(P);
	for (int i = 1; i <= sP; ++i) {
		if (P % i == 0) {
			ans.push_back(i);
			if (P / i != i)
				ans.push_back(P / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		if (ans[i] > L)
			printf(" %d", ans[i]);
	printf("\n");
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:", _);
		solve();
	}
	return 0;
}
