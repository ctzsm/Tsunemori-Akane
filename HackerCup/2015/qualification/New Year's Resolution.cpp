#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int a[20][3], fa[3];
int main() {
	freopen("new_years_resolution.txt", "r", stdin);
	freopen("new_years_resolution.out", "w", stdout);
	int __;
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		scanf("%d%d%d", &fa[0], &fa[1], &fa[2]);
		int N; scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		bool ans = false;
		for (int i = 0; i < (1 << N); ++i) {
			int ga[3] = {0, 0, 0};
			for (int j = 0; j < N; ++j) {
				if (i & (1 << j)) {
					for (int k = 0; k < 3; ++k) ga[k] += a[j][k];
				}
			}
			bool flag = true;
			for (int j = 0; j < 3; ++j) 
				if (ga[j] != fa[j])
					flag = false;
			if (flag) {
				ans = true;
				break;
			}
		}
		printf("Case #%d: ", _);
		puts(ans ? "yes" : "no");
	}
	return 0;
}