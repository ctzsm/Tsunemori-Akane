#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int k,n;
char s[1000005];
long long ans = 0;
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%d%s",&k,s+1);
	n = strlen(s+1);
//	printf("%s\n",s+1);
	if(k == 0){
		long long cnt = 0;
		for(int i = 1;i <= n; ++i){
			if(s[i] == '0'){
				cnt++;
			}else{
				ans += (cnt + 1) * cnt / 2;
				cnt = 0;
			}
		}
		ans += (cnt + 1) * cnt / 2;
		cout << ans << endl;
		return 0;
	}
	int i = 1,j = 1,cnt = s[1] == '1' ? 1 : 0;
	while(i <= n && j <= n){
		if(cnt == k){
			long long left = 1,right = 1;
			while(s[i] == '0') left++,i++;
			while(s[j+1] == '0') right++,j++;
			ans += left * right;
			i++;cnt--;
		}else if(cnt < k){
			j++;
			if(s[j] == '1') cnt++;
//			printf("%d %d %d\n",i,j,cnt);
		}
	}
	cout << ans << endl;
	return 0;
}

