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
//����
int n,k;
int a[MAX_N];
int b[MAX_N];
int dep[MAX_N];	//˫�˶���

void solve(){
	int s=0,t=0;	//˫�˶��е�ͷ����ĩβ
	for(int i=0;i<n;i++){
		//��˫�˶���ĩβ����i
		while(t>s&&dep[a[t-1]]>=a[i])t--;
		dep[t++]=i;
		
		if(i-k+1>=0){
			b[i-k+1]=a[dep[s]];
		}

		//��ͷ��ɾ��Ԫ��
		if(dep[s]==i-k+1){
			s++;
		}
	}
	for(int i=0;i+k-1<n;i++){
		printf("\%d%c",b[i],i+k==n?'\n':' ');
	}
}

int main()
{
	return 0;
}

