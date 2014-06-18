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

//输入
int N,K;
string S;
int Next[MAX_K][4];	//添加某个字符后转移到的状态
int dp[MAX_N+1][MAX_K];	

void solve(){
	//预处理
	for(int i=0;i<K;i++){
		for(int j=0;j<4;j++){
			//在S长度为i的前缀后添加一个字符
			string s=S.substr(0,i)+AGCT[j];
			//反复删除第一个字符，直到成为S的前缀
			while(S.substr(0,s.length())!=s){
				s=s.substr(1);
			}
			Next[i][j]=s.length();
		}
	}
	//动态规划初值，长度为0且后缀长为0时（只能为0）的个数
	dp[0][0]=1;
	for(int i=1;i<K;i++)dp[0][i]=0;
	for(int t=0;t<N;t++){
		for(int i=0;i<K;i++)dp[t+1][i]=0;

		for(int i=0;i<K;i++){
			for(int j=0;j<4;j++){
				int ti=Next[i][j];
				//禁止字符串出现
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

