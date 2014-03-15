#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[6005],t[2005];

int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%s%s",s + 2000,t);
	int ans = 0;
	int lens = strlen(s + 2000),lent = strlen(t);
	for(int i = 0;i < 2000 + lens; ++i){
		int cnt = 0;
		for(int j = 0;j < lent; ++j)
			cnt += s[i+j] == t[j];
		ans = max(ans,cnt);
	}
	printf("%d\n",lent - ans);
	return 0;
}

