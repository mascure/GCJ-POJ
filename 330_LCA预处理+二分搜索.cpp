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
const int MAX_LOG_V=20;
//输入
vector<int> G[MAX_V];	//图的邻接表表示
int root;	//根节点编号
int parent[MAX_LOG_V][MAX_V];	//向上走2^步所到的节点 超过根
int depth[MAX_V];

void dfs(int v,int p,int d){
	parent[0][v]=p;
	depth[v]=d;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]!=p)dfs(G[v][i],v,d+1);
	}
}
void init(int V){
	memset(parent,-1,sizeof(parent));
	//预处理出parent[0]和depth
	dfs(root,-1,0);
	//预处理出parent
	for(int k=0;k+1<MAX_LOG_V;k++){
		for(int v=0;v<V;v++){
			if(parent[k][v]<0)parent[k+1][v]=-1;
			else parent[k+1][v]=parent[k][parent[k][v]];
		}
	}
}
//计算u和v的LCA
int lca(int u,int v){
	//让u和v向上走到同一深度
	if(depth[u]>depth[v])swap(u,v);
	for(int k=0;k<MAX_LOG_V;k++){
		if((depth[v]-depth[u])>>k&1)v=parent[k][v];
	}
	if(u==v)return u;
	//利用二分搜索计算LCA
	for(int k=MAX_LOG_V-1;k>=0;k--){
		if(parent[k][u]!=parent[k][v]){
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];
}
int main()
{
	return 0;
}

