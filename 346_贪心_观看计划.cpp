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
int N,M;
int s[MAX_N],t[MAX_N];
pair<int,int> ps[MAX_N*2];	//���ս���ʱ�������ʹ�õ����Ե�����

void solve(){
	int res=0;

	//��ԭ�������ݸ���һ�ݴ��ں���
	for(int i=0;i<N;i++){
		if(t[i]<s[i])t[i]+=M;
		s[N+i]=s[i]+M;
		t[N+i]=t[i]+M;
	}
	//���ս���ʱ������
	for(int i=0;i<N*2;i++){
		ps[i]=make_pair(t[i],s[i]);
	}
	sort(ps,ps+2*N);
	//ȷ��һ���ʼ��ʱ��
	for(int i=0;i<N;i++){
		int tmp=0,last=0;
		for(int j=i;ps[j].first<ps[i].second+M;j++){
			if(last<=ps[i].second){
				tmp++;
				last=ps[j].first;
			}
		}
		res=max(res,tmp);
	}
	cout<<res<<endl;
}
int main()
{
	
	return 0;
}

