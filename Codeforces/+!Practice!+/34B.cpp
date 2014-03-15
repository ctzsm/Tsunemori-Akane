#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m;
int a[110];
int main(int argc, char** argv) {
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	sort(a,a+n);
	int ans = 0;
	for(int i = 0;i < m; ++i){
		if(a[i] < 0) ans += a[i];
		if(a[i] >= 0) break;
	}
	printf("%d\n",-ans);
	return 0;
}

