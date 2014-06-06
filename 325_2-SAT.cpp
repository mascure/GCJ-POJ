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
#define MAX_N 105
#define MAX_M 50005
typedef long long ll;
using namespace std;
int V;		//������
vector<int> G[MAX_V];	//ͼ���ڽӱ��ʾ
vector<int> rG[MAX_V];	//�ѱ߷�����ͼ
vector<int> vs;			//	�������˳��Ķ����б�
bool used[MAX_V];		//���ʱ��
int cmp[MAX_V];			//����ǿ��ͨ��������������
void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}
int scc(){
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++){
		if(!used[v]) dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int v=vs.size()-1;v>=0;v--){
		if(!used[vs[v]]) rdfs(vs[v],k++);
	}
	return k;
}
//2-SAT ����
//����ǿ��ͨ�����������ڲ�����ʽ�Ӿ���������ʱ�������
//�����̺�����ÿ���־�a��b��Ϊ-a��b^-b��a,��ÿ����������x��������������ֱ����x��-x���ԡ���ϵΪ�߽�������ͼ
//��ʱ�����a���ܹ�����b��Ļ��ͱ�ʾaΪ��ʱbҲһ��Ϊ�棬��ˣ�ͬһ��ǿ��ͨ�������������������ֵĲ���ֵ����ͬ
//�������ĳ��x��x��-x��ͬһ��ǿ��ͨ�����У����޷�������������ʽ��ֵΪ�棬��֮����������������Ĳ�����������
//��x���ڵ�ǿ��ͨ��������������-x���ڵ�ǿ��ͨ����֮��ʱ��xΪ��
void solve(){
	//���ߣ�0~N-1����a,b,c��..
	//N~2*N-1����-a,-b,-c
	scc();
	bool res=true;
	for(int i=0;i<N;i++){
		if(cmp[i]==cmp[N+i])
			res=false;
		return;
	}
	//��������㣬�����һ���
	bool b[MAX_N];
	for(int i=0;i<N;i++){
		if(cmp[i]>cmp[N+i])
			b[i]=true;
		else
			b[i]=false;
	}
}
int main()
{
	
	return 0;
}

