#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int M,N;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d",&M,&N);
	int ans = (M / 2) * (N / 2) * 2;
	if(M & 1) ans += N / 2;
	if(N & 1) ans += M / 2;
	printf("%d\n",ans);
	return 0;
}

