#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<math.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_N 100005
#define MAX_M 50005
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
const ull B=100000007;
using namespace std;

//a是否在b中出现过
bool contain(string a,string b){
	int al=a.length(),bl=b.length();
	if(al>bl)return false;

	ull t=1;
	for(int i=0;i<al;i++)t*=B;
	//计算a和b长度为al的前缀对应的哈希值
	ull ah=0,bh=0;
	for(int i=0;i<al;i++)ah=ah*B+a[i];
	for(int i=0;i<al;i++)bh=bh*B+b[i];
	//对b不断右移一位，更新哈希值
	for(int i=0;i+al<=bl;i++){
		if(ah==bh)return true;
		if(i+al<bl) bh=bh*B+b[i+al]-b[i]*t;
	}
	return false;
}

//a的后缀和b的前缀相等的
int overlap(string a,string b){
	int al=a.length(),bl=b.length();
	int ans=0;
	ull ah=0,bh=0,t=1;
	for(int i=1;i<=al;i++){
		ah=ah+a[al-i]*t;		//a的长度为i的后缀的哈希值
		bh=bh+b[i-1]*t;		//b的长度为i的前缀的哈希值
		if(ah==bh)ans=i;
		t*=B;
	}
	return ans;
}
int main(){
	return 0;
}

