#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1000005;
const long long mod = 1000000007;
class Matrix{
public:
	long long a[4][4];
	Matrix(){
		memset(a,0,sizeof(a));
	}
	Matrix operator + (const Matrix& b)const{
		Matrix ret;
		for(int i = 0;i < 4; ++i) for(int j = 0;j < 4; ++j){
			ret.a[i][j] = a[i][j] + b.a[i][j];
			ret.a[i][j] %= mod;
		}
		return ret;
	}
	Matrix operator * (const Matrix& b)const{
		Matrix ret;
		for(int i = 0;i < 4; ++i){
			for(int j = 0;j < 4; ++j){
				for(int k = 0;k < 4; ++k){
					ret.a[i][j] += a[i][k] * b.a[k][j];
					ret.a[i][j] %= mod;
				}
			}
		}
		return ret;
	}
	Matrix pow(int k){
		if(k == 0 || k == 1) return (*this);
		Matrix tmp = pow(k >> 1);
		tmp = tmp * tmp;
		if(k & 1) return tmp * (*this);
		else return tmp;
	}
	void print(){
		for(int i = 0;i < 4; ++i){
			for(int j = 0;j < 4; ++j) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
};
int n;
int A[maxn],B[maxn],C[maxn],D[maxn];
int main(int argc, char** argv) {
	scanf("%d",&n);
	if(n == 1){
		printf("0\n");return 0;
	}
	Matrix ans,coe;ans.a[3][0] = 1;
	for(int i = 0;i < 4; ++i) for(int j = 0;j < 4; ++j){
		if(i == j) coe.a[i][j] = 0;
		else coe.a[i][j] = 1;
	}
//	ans.print();coe.print();
//	(coe * ans).print();
	ans = coe.pow(n) * ans;
//	ans.print();
	printf("%d\n",(int)ans.a[3][0]);
	return 0;
}

