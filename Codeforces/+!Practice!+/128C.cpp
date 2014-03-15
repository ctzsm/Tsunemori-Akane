#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mod = 1000000007;

long long C[1005][1005];
int n,m,k;
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	k <<= 1;
	if(n - 1 < k || m - 1 < k){ cout << "0" << endl;return 0; }
	for(int i = 0;i <= 1000; ++i) for(int j = 0;j <= i; ++j)
		C[i][j] = (i == 0 || i == j ? 1 : C[i - 1][j] + C[i-1][j-1]) % mod;
	cout << (C[n-1][k] * C[m-1][k]) % mod << endl;
	return 0;
}

