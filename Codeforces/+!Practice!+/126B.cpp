#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[1000005];
int next[1000005];

void preKmp(char *x, int m, int kmpNext[]) {
	int i = 0, j;
	j = kmpNext[0] = -1;
	while (i < m) {
		while(j > -1 && x[i] != x[j]) j = kmpNext[j];
		i++,j++;
		kmpNext[i] = j;
	}
}

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%s", s);
	int n = strlen(s);
	preKmp(s, n, next);
	for(int i = 0;i <= n; ++i) printf("%d ",next[i]);
	printf("\n");
	if (next[n] == 0) {
		puts("Just a legend");
		return 0;
	}
	for (int i = n - 1; i >= 0; --i) if (next[i] == next[n]) {
			for (int j = 0; j < next[n]; ++j) putchar(s[j]);
			puts("");
			return 0;
		}
	if (next[next[n]] != 0) {
		for (int i = 0; i < next[next[n]]; ++i) putchar(s[i]);
		puts("");
		return 0;
	}
	puts("Just a legend");
	printf("\n");
	return 0;
}

