#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int gl,gr,bl,br;
bool check(int x,int y){
	int down = y / 2 + (y & 1);
	int up = y;
	if(x - 1 <= y && x - 1 >= down) return true;
	if(x <= y && x >= down) return true;
	if(x + 1 <= y && x + 1 >= down) return true;
	return false;
}
int main(int argc, char** argv) {
	scanf("%d%d%d%d",&gl,&gr,&bl,&br);
	bool ans = check(gl,br);
	ans |= check(gr,bl);
	if(ans) puts("YES");
	else puts("NO");
	return 0;
}

