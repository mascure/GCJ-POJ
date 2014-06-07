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
#define MAX_N 1005
#define MAX_M 50005
typedef long long ll;
using namespace std;
//����
vector<int> G[MAX_V];	//ͼ���ڽӱ��ʾ
int root;	//���ڵ���
int parent[MAX_V];
int depth[MAX_V];

void dfs(int v,int p,int d){
	parent[v]=p;
	depth[v]=d;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]!=p)dfs(G[v][i],v,d+1);
	}
}
void init(){
	dfs(root,-1,0);
}
//����u��v��LCA
int lca(int u,int v){
	//��u��v�����ߵ�ͬһ���
	while(depth[u]>depth[v])u=parent[u];
	while(depth[v]>depth[u])v=parent[v];
	while(u!=v){
		u=parent[u];
		v=parent[v];
	}
	return u;
}
int main()
{
	return 0;
}

