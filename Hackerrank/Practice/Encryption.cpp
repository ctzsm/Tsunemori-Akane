#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[100];
int main() {
	freopen("in", "r", stdin);
	scanf("%s", s);
	int n = strlen(s), r = 0, c = 0;
	int ln = (int)(sqrt(n) + 0.05);
	if (ln * ln >= n) r = c = ln;
	else if (ln * (ln + 1) >= n) r = ln, c = ln + 1;
	else r = c = ln + 1;
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < r; ++j)
			if (j * c + i < n)
				putchar(s[j * c + i]);
			else
				break;
		putchar(' ');
	}
	return 0;
}
