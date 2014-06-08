#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_N 100005
#define MAX_M 50005
typedef long long ll;
using namespace std;
//输入
int n;
int h[MAX_N];

int L[MAX_N],R[MAX_N];
int st[MAX_N];	//栈

void solve(){
	int t=0;	//栈的大小
	//计算L
	for(int i=0;i<n;i++){
		while(t>0&&h[st[t-1]]>=h[i])t--;
		L[i]=t==0?0:(st[t-1]+1);
		st[t++]=i;
	}
	//计算R
	t=0;
	for(int i=n-1;i>=0;i--){
		while(t>0&&h[st[t-1]]>=h[i])t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
	ll res=0;
	for(int i=0;i<n;i++){
		res=max(res,(ll)h[i]*(R[i]-L[i]));
	}
	printf("%lld\n",res);
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++)scanf("%d",&h[i]);
		solve();
	}
	return 0;
}

