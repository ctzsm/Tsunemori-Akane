#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int getAns(void) {
	char s[15];
	scanf("%s", s);
	int n = strlen(s);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans *= 10;
		ans += s[i] - '0';
	}
	int ans2 = ans;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (i == 0 && s[j] == '0') 
				continue;
			swap(s[i], s[j]);
			int t = 0;
			for (int k = 0; k < n; ++k) {
				t *= 10;
				t += s[k] - '0';
			}
			ans = min(ans, t);
			ans2 = max(ans2, t);
			swap(s[i], s[j]);
		}
	}
	printf("%d %d\n", ans, ans2);
}
int main() {
	freopen("cooking_the_books.txt", "r", stdin);
	freopen("cooking_the_books.out", "w", stdout);
	int __;
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		getAns();
	}
	return 0;
}