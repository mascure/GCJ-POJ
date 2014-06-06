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
#define MAX_V 500
#define MAX_N 105
#define MAX_M 20;
typedef long long ll;
using namespace std;
int V;		//顶点数
vector<int> G[MAX_V];	//图的邻接表表示
vector<int> rG[MAX_V];	//把边反向后的图
vector<int> vs;			//	后序遍历顺序的顶点列表
bool used[MAX_V];		//访问标记
int cmp[MAX_V];			//所属强连通分量的拓扑排序
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
	for(int i=0;i<rG[v].size;i++){
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

int main()
{
	return 0;
}

