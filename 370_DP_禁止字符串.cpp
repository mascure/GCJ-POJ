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
using namespace std;
const char *AGCT="AGCT";
const int MOD = 10009;

//����
int N,K;
string S;
int Next[MAX_K][4];	//���ĳ���ַ���ת�Ƶ���״̬
int dp[MAX_N+1][MAX_K];	

void solve(){
	//Ԥ����
	for(int i=0;i<K;i++){
		for(int j=0;j<4;j++){
			//��S����Ϊi��ǰ׺�����һ���ַ�
			string s=S.substr(0,i)+AGCT[j];
			//����ɾ����һ���ַ���ֱ����ΪS��ǰ׺
			while(S.substr(0,s.length())!=s){
				s=s.substr(1);
			}
			Next[i][j]=s.length();
		}
	}
	//��̬�滮��ֵ������Ϊ0�Һ�׺��Ϊ0ʱ��ֻ��Ϊ0���ĸ���
	dp[0][0]=1;
	for(int i=1;i<K;i++)dp[0][i]=0;
	for(int t=0;t<N;t++){
		for(int i=0;i<K;i++)dp[t+1][i]=0;

		for(int i=0;i<K;i++){
			for(int j=0;j<4;j++){
				int ti=Next[i][j];
				//��ֹ�ַ�������
				if(ti==K)continue;
				dp[t+1][ti]=(dp[t+1][ti]+dp[t][i])%MOD;
			}
		}
	}
	int ans=0;
	for(int i=0;i<K;i++)ans=(ans+dp[N][i])%MOD;
	cout<<ans<<endl;
}
int main(){
	return 0;
}

