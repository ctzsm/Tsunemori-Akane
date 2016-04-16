#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int cnt[2505];
void solve() {
	scanf("%d", &N);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < 2 * N - 1; ++i) {
		for (int j = 0; j < N; ++j) {
			int x; scanf("%d", &x);
			cnt[x] ++;
		}
	}
	for (int i = 1; i <= 2500; ++i) {
		if (cnt[i] & 1) printf(" %d", i);
	}
	printf("\n");
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:", _);
		solve();
	}
	return 0;
}
