#include <cstdio>

using namespace std;

int main() {
	freopen("in", "w", stdout);
	printf("257\n");
	for (int i = 3; i < 6; ++i)
		for (int j = 0; j < 20; ++j)
			for (int k = j; k < 20; ++k)
				if ((j + 1) * (k + 1) % (i + 1) == 0)
					printf("%d %d %d\n", i + 1, j + 1, k + 1);
	return 0;
}