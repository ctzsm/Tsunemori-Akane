#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

char s[1000005];
int a[1000005];
stack<int> sta;
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%s",s);
	int len = strlen(s);
	int ans = 0,clen = 0;
	for(int i = 0;i < len; ++i){
		if(s[i] == '('){
			sta.push(i);
		}else{
			if(!sta.empty()){
				int match = sta.top();sta.pop();
				int now = i - match + 1;
				now = match == 0 ? now : now + a[match-1];
				a[i] = now;
				if(clen < now){
					clen = now;
					ans = 1;
				}else if(clen == now) ans++;
			}
		}
	}
	if(clen == 0) printf("0 1\n");
	else printf("%d %d\n",clen,ans);
	return 0;
}

