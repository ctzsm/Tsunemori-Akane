#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000000;
bool isNotPrime[N + 5] = {true, true};
int cnt[N + 5];
void getPrime() {
	for (int i = 2; i <= N; ++i) {
		if (!isNotPrime[i]) {
			cnt[i] = 1;
			for (int j = i + i; j <= N; j += i) {
				cnt[j] ++;
				isNotPrime[j] = true;
			}
		}
	}
}
void solve() {
	int A, B, K;
	scanf("%d%d%d", &A, &B, &K);
	int ans = 0;
	for (int i = A; i <= B; ++i) 
		if (cnt[i] == K) ans++;
	printf("%d\n", ans);
}
int main() {
	// freopen("homework.txt", "r", stdin);
	// freopen("homework.out", "w", stdout);
	getPrime();
	printf("%d\n", cnt[17]);
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}