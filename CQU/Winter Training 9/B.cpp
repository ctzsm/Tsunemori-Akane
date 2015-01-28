#include <cstdio>

using namespace std;

int n, B, D, f, F;
char s[50000];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d%d%d%d", &n, &B, &D, &f, &F)) {
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			int tot = 0;
			for (int j = 0; s[j]; ++j) {
				if (s[j] == 'A')
					tot += B + D + f;
				if (s[j] == 'B') 
					tot += ((B + D) << 1) + F;
				if (s[j] == 'C')
					tot += (B + D) * 3 + (F << 1);
			}
			if (ans == -1 || ans > tot) ans = tot;
		}
		printf("%d\n", ans);
	}
	return 0;
}