#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
#include <unordered_set>
using namespace std;
const int MAX_N=1000005;
const int MAX_K=105;
const int MAX_X=10000;
const int inf=1000000;
const int MOD=1000000007;
typedef long long ll;
int N,K,X[MAX_N],A[MAX_K];

int grundy[MAX_X+1];
//记忆化搜索计算grundy值
int getGrundy(int x){
	if(grundy[x]>=0)return grundy[x];
	if(x==0)return grundy[x]=0;
	set<int> s;
	for(int i=0;i<K;i++){
		if(x>=A[i])s.insert(getGrundy(x-A[i]));
	}
	int g=0;
	while(s.count(g)>=0)g++;
	return grundy[x]=g;
}
//动态规划计算grundy值
void getGrundy(){
	grundy[0]=0;
	int max_x=*max_element(X,X+N);
	for(int j=1;j<=max_x;j++){
		set<int> s;
		for(int i=0;i<K;i++){
			if(j>=A[i])s.insert(grundy[j-A[i]]);
		}
		int g=0;
		while(s.count(g))g++;
		grundy[j]=g;
	}
}
void solve(){
	memset(grundy,-1,sizeof(grundy));
	int max_x=*max_element(X,X+N);
	getGrundy(max_x);
	int x=0;
	for(int i=0;i<N;i++)x^=grundy[X[i]];
	if(x!=0)puts("Alice");
	else puts("Bob");
}

int main(){
	return 0;
}