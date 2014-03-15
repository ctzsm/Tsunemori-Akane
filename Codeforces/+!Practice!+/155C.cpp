#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100005];
char match[15][15];
int k,n,ans = 0;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%s%d",s,&k);
	n = strlen(s);
	for(int i = 0;i < k; ++i) scanf("%s",match[i]);
	for(int i = 0;i < k; ++i){
		int cnt1 = 0,cnt2 = 0;
		for(int j = 0;j < n; ++j){
			if(match[i][0] == s[j]){
				cnt1++;
			}else if(match[i][1] == s[j]){
				cnt2++;
			}else{
				ans += min(cnt1,cnt2);
				cnt1 = cnt2 = 0;
			}
		}
		ans += min(cnt1,cnt2);
	}
	printf("%d\n",ans);
	return 0;
}

