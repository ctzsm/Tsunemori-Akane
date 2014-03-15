#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n,x;
int a[1005];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d",&n,&x);
	for(int i = 1;i <= n; ++i) scanf("%d",&a[i]);
	for(int ans = 0;ans <= 501; ++ans){
		sort(a+1,a+n+1);
		int mid = (n + 1) >> 1;
		if(a[mid] == x){
			printf("%d\n",ans);
			break;
		}
		a[++n] = x;
	}
	return 0;
}

