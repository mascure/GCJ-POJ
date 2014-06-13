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
const int MAX_MATCH=65;
const int MAX_SQUARE=60;
//������(2N(N+1))����������(N(N+1)(2N+1)/6)
int M,S;
//m[i][j]=true��ʾ����i����������j
bool m[MAX_MATCH][MAX_SQUARE];
//mmax[i]��ʾ������j�л����������
int mmax[MAX_SQUARE];

//����p�Ժ�Ļ��ʱ����½�
int hstar(int p,vector<bool> state){
	vector<pair<int,int> > ps;
	for(int i=0;i<S;i++){
		if(state[i]){
			//ͳ��ʣ�������ΰ����Ļ�����
			int num=0;
			for(int j=p;j<M;j++){
				if(m[j][i])num++;
			}
			ps.push_back(make_pair(num,i));
		}
	}
	//����������С��������
	sort(ps.begin(),ps.end());
	int res=0;
	//used[i]=true ��ʾ��ǰ�������Ѿ��а�������i����������
	vector<bool> used(M,false);
	for(int i=0;i<ps.size();i++){
		int id=ps[i].second;
		bool ok=true;
		//�ж��Ƿ�������id����x��
		for(int j=p;j<M;j++){
			if(used[j]&&m[j][id])ok=false;
		}
		if(ok){
			res++;
			for(int j=p;j<M;j++){
				if(m[j][id])used[j]=true;
			}
		}
	}
	return res;
}

//p�ǵ�ǰ����Ļ�����ţ�num�������Ѿ��Ƴ��Ļ����ĸ���
//state[i]=true��ʾ������i��δ���ƻ�
//�Ѿ��ҵ������Ž�
int min_res;
int dfs(int p,int num,vector<bool> state){
	//�������������л�����Ҳ���ƻ������е�������
	if(p==M)return min_res=num;
	
	//�������֪�����Ž�Ҫ��򲻼�������
	if(num+hstar(p,state)>=min_res) return inf;

	//���һ��Ҫ�Ƴ�����p����use=true
	//���һ�����Ƴ�����p���Ƴ������ƻ��κ������Σ�����notuse=true
	bool use=false,notuse=true;
	for(int i=0;i<S;i++){
		//���p���ƻ�������i��������Ƴ�
		if(state[i]&&m[p][i])notuse=false;
		//ֻʣ����p�����ƻ�������i�ˣ�������Ƴ�
		if(state[i]&&mmax[i]==p)use=true;
	}

	int res=inf;
	//���Ƴ�p
	if(!use)res=min(res,dfs(p+1,num,state));
	for(int i=0;i<S;i++){
		if(m[p][i])state[i]=false;
	}
	//�Ƴ�����
	if(!notuse)res=min(res,dfs(p+1,num+1,state));
	return res;
}

void solve(){
	vector<bool> state(S,true);
	cout<<dfs(0,0,state)<<endl;
}

int main()
{
	return 0;
}

