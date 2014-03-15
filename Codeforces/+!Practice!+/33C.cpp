#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,a[100005];
int sum[100005];
int left[100005],right[100005];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	sum[0] = a[0];
	for(int i = 1;i < n; ++i) sum[i] = sum[i-1] + a[i];
	left[0] = max(a[0],-a[0]);
	for(int i = 1;i < n; ++i) left[i] = max(left[i-1] + a[i],-sum[i]);
	sum[n-1] = a[n-1];
	for(int i = n - 2;i >= 0; --i) sum[i] = sum[i+1] + a[i];
	right[n-1] = max(a[n-1],-a[n-1]);
	for(int i = n - 2;i >= 0; --i) right[i] = max(right[i+1] + a[i],-sum[i]);
	int ans = max(right[0],left[n-1]);
	for(int i = 0;i < n - 1; ++i) ans = max(ans,left[i] + right[i+1]);
	printf("%d\n",ans);
	return 0;
}

