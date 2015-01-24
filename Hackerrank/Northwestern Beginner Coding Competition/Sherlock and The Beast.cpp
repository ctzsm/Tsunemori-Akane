#include <bits/stdc++.h>

using namespace std;

int T, N;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		bool flag = false;
		for (int i = N / 3; i >= 0; --i) {
			if ((N - i * 3) % 5 == 0) {
				for (int j = 0; j < i * 3; ++j) putchar('5');
				for (int j = 0; j < N - i * 3; ++j) putchar('3');
				printf("\n");
				flag = true;
				break;
			}
		}
		if (!flag) printf("-1\n");
	}
	return 0;
}