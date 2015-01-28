#include <cstdio>

using namespace std;

int n, m;
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i <= m + 1; ++i) {
			for (int j = 0; j <= n + 1; ++j) {
				if ((i == 0 && j == 0) ||
					(i == 0 && j == n + 1) ||
					(i == m + 1 && j == 0) ||
					(i == m + 1 && j == n + 1))
					putchar('+');
				else if (i == 0 || i == m + 1)
					putchar('-');
				else if (j == 0 || j == n + 1)
					putchar('|');
				else
					putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}