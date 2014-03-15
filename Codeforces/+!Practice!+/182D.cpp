#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

char s1[100005],s2[100005];
int len1,len2;
bool check(int len){
	int t1 = len1 / len;
	int t2 = len2 / len;
	int b = 0;
	for(int i = 0;i < t1; ++i){
		for(int j = 0;j < len; ++j){
			if(s1[b + j] != s1[j]) return false;
		}
		b += len;
	}
	b = 0;
	for(int i = 0;i < t2; ++i){
		for(int j = 0;j < len; ++j){
			if(s2[b + j] != s1[j]) return false;
		}
		b += len;
	}
	return true;
}
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%s%s",s1,s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	int gcd = __gcd(len1,len2),ans = 0;
	for(int i = 1;i <= gcd; ++i){
		if(gcd % i == 0){
//			printf("%d\n",i);
			if(check(i)) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

