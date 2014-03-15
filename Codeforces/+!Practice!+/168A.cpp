#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,x,y;
int main(int argc, char** argv) {
	scanf("%d%d%d",&n,&x,&y);
	int ans = n * y;
	ans = (ans - 1) / 100 + 1 - x;
	if(ans < 0) ans = 0;
	printf("%d\n",ans);
	return 0;
}

