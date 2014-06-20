#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,k;
int Rank[MAX_N+1],tmp[MAX_N+1];
//比较rank[i],rank[i+k]和rank[j],rank[j+k]
bool compare_sa(int i,int j){
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	else{
		int ri=i+k<n?Rank[i+k]:-1;
		int rj=k+k<n?Rank[k+k]:-1;
		return ri<rj;
	}
}
//计算字符串S的后缀数组
void construct_sa(string S,int *sa){
	n=S.length();
	//初始长度为1，rank直接取字符的编码
	for(int i=0;i<=n;i++){
		sa[i]=i;
		Rank[i]=i<n?S[i]:-1;
	}
	//利用长度为k的排序的结果对长度为2k的排序
	for(int k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,compare_sa);
		//先在tmp中临时存储新计算的rank
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++){
			tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
		}
		for(int i=0;i<=n;i++)
			Rank[i]=tmp[i];
	}
}
bool contain(string S,int *sa,string T){
	int a=0,b=S.length();
	while(b-a>1){
		int c=(a+b)/2;
		if(S.compare(sa[c],T.length(),T)<0)a=c;
		else
			b=c;
	}
	return S.compare(sa[b],T.length(),T)==0;
}
int main(){
	return 0;
}

