#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int r,g,b;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d%d",&r,&g,&b);
	r = ((r + 1) / 2 - 1) * 3;
	g = ((g + 1) / 2 - 1) * 3 + 1;
	b = ((b + 1) / 2 - 1) * 3 + 2;
	printf("%d\n",max(r,max(g,b)) + 30);
	return 0;
}

