#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
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
#define MAX_N 20005
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
//�Ƚ�rank[i],rank[i+k]��rank[j],rank[j+k]
bool compare_sa(int i,int j){
	if(Rank[i]!=Rank[j])return Rank[i]<Rank[j];
	else{
		int ri=i+k<=n?Rank[i+k]:-1;
		int rj=j+k<=n?Rank[j+k]:-1;
		return ri<rj;
	}
}
//�����ַ���S�ĺ�׺����
void construct_sa(string S,int *sa){
	n=S.length();
	//��ʼ����Ϊ1��rankֱ��ȡ�ַ��ı���
	for(int i=0;i<=n;i++){
		sa[i]=i;
		Rank[i]=i<n?S[i]:-1;
	}
	//���ó���Ϊk������Ľ���Գ���Ϊ2k������
	for(k=1;k<=n;k<<=1){
		sort(sa,sa+n+1,compare_sa);
		//����tmp����ʱ�洢�¼����rank
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

//�����ַ���S�Ͷ�Ӧ�ĺ�׺����sa������߶�����lcp
void construct_lcp(string S,int *sa,int *lcp){
	int n=S.length();
	for(int i=0;i<=n;i++)Rank[sa[i]]=i;

	int h=0;
	lcp[0]=0;
	for(int i=0;i<n;i++){
		//�����λ��i��ʼ�ĺ�׺�ں�׺�����е�ǰһ����׺��lcp
		int j=sa[Rank[i]-1];
		//��h��ȥ����ĸ��1���ȣ��ڱ���ǰ׺��ͬǰ���²�������
		if(h>0)h--;
		for(;j+h<n&&i+h<n;h++){
			if(S[j+h]!=S[i+h])break;
		}
		lcp[Rank[i]-1]=h;
	}
}
//����
string S,T;
int sa[MAX_N],lcp[MAX_N];

void solve(){
	int s1=S.length();
	S+='$'+T;
	construct_sa(S,sa);
	construct_lcp(S,sa,lcp);

	int ans=0;
	for(int i=0;i<S.length();i++){
		if((sa[i]<s1)!=(sa[i+1]<s1)){
			ans=max(ans,lcp[i]);
		}
	}
	cout<<ans;
}
int main(){
	freopen("in.txt","r",stdin);
	int caseN;
	cin>>caseN;
	while(caseN--){
		getchar();
		getline(cin,S);
		getline(cin,T);
		cout<<"Nejdelsi spolecny retezec ma delku ";
		solve();
		cout<<"."<<endl;
	}
	return 0;
}

