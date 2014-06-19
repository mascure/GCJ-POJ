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

//a�Ƿ���b�г��ֹ�
bool contain(string a,string b){
	int al=a.length(),bl=b.length();
	if(al>bl)return false;

	ull t=1;
	for(int i=0;i<al;i++)t*=B;
	//����a��b����Ϊal��ǰ׺��Ӧ�Ĺ�ϣֵ
	ull ah=0,bh=0;
	for(int i=0;i<al;i++)ah=ah*B+a[i];
	for(int i=0;i<al;i++)bh=bh*B+b[i];
	//��b��������һλ�����¹�ϣֵ
	for(int i=0;i+al<=bl;i++){
		if(ah==bh)return true;
		if(i+al<bl) bh=bh*B+b[i+al]-b[i]*t;
	}
	return false;
}

//a�ĺ�׺��b��ǰ׺��ȵ�
int overlap(string a,string b){
	int al=a.length(),bl=b.length();
	int ans=0;
	ull ah=0,bh=0,t=1;
	for(int i=1;i<=al;i++){
		ah=ah+a[al-i]*t;		//a�ĳ���Ϊi�ĺ�׺�Ĺ�ϣֵ
		bh=bh+b[i-1]*t;		//b�ĳ���Ϊi��ǰ׺�Ĺ�ϣֵ
		if(ah==bh)ans=i;
		t*=B;
	}
	return ans;
}
int main(){
	return 0;
}

