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

int N,M,P,Q,T;
char field[MAX_SIZE][MAX_SIZE];	//ƥ�����
char patterns[MAX_T][MAX_SIZE][MAX_SIZE];	//ƥ��ģʽ
ull Hash[MAX_SIZE][MAX_SIZE],tmp[MAX_SIZE][MAX_SIZE];
//����a������P*Q�����Ӧ�Ĺ�ϣֵ
void compute_hash(char a[MAX_SIZE][MAX_SIZE],int n,int m){
	const ull B1=9973;
	const ull B2=100000007;

	//���з�������ϣֵ
	ull t1=1;
	for(int j=0;j<Q;j++)t1*=B1;

	for(int i=0;i<n;i++){
		ull e=0;
		for(int j=0;j<Q;j++)e=e*B1+a[i][j];

		for(int j=0;j+Q<=m;j++){
			tmp[i][j]=e;
			if(j+Q<m)e=e*B1+a[i][j+Q]-a[i][j]*t1;
		}
	}

	//���з�������ϣֵ
	ull t2=1;
	for(int j=0;j<P;j++)t2*=B2;

	for(int i=0;i+Q<=m;i++){
		ull e=0;
		for(int j=0;j<P;j++)e=e*B2+tmp[j][i];

		for(int j=0;j+P<=n;j++){
			Hash[j][i]=e;
			if(j+P<n)e=e*B2+tmp[j+P][i]-tmp[j][i]*t2;
		}
	}
}

void solve(){
	//�����е�ģʽ�Ĺ�ϣֵ����mutiset��
	multiset<ull> unseen;
	for(int k=0;k<T;k++){
		compute_hash(patterns[k],P,Q);
		unseen.insert(Hash[0][0]);
	}
	compute_hash(field,N,M);
	//�����ֵĹ�ϣֵ��multiset���޳�
	for(int i=0;i+P<=N;i++){
		for(int j=0;j+Q<=M;j++){
			unseen.erase(Hash[i][j]);
		}
	}
	cout<<T-unseen.size()<<endl;
}
int main(){
	int caseN=1;
	while(scanf("%d%d%d%d%d",&N,&M,&T,&P,&Q)!=EOF){
		if(N==0&&M==0&&T==0&&P==0&&Q==0)break;
		getchar();
		for(int i=0;i<N;i++){
			scanf("%s",field[i]);
		}
		for(int k=0;k<T;k++){
			getchar();
			for(int i=0;i<P;i++)
				scanf("%s",patterns[k][i]);
		}
		cout<<"Case "<<caseN++<<": ";
		solve();
	}
	return 0;
}

