#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int v, a[10];
int main(void)
{
//	freopen("in", "r", stdin);
    scanf("%d", &v);
    for (int i = 1; i <= 9; ++i) scanf("%d", &a[i]);
    int s = 0x7fffffff, id = 0;
    for (int i = 1; i <= 9; ++i) {
        if (s >= a[i]) {
            s = a[i];
            id = i;
        }
    }
    s = v / s;
    if (s <= 0) {
    	printf("-1\n");
    	return 0;
    }
    v -= s * a[id];
    for (int i = 0; i < s; ++i) {
    	for (int j = 9; j > 0; --j) {
    		if (v >= a[j] - a[id]) {
    			printf("%d", j);
    			v -= a[j] - a[id];
    			break;
    		}
    	}
    }
    printf("\n");
    return 0;
}