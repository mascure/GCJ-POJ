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
//输入
int N,M;
int A[MAX_M],B[MAX_M];
void solve(){
	V=N;
	for(int i=0;i<M;i++){
		add_edge(A[i]-1,B[i]-1);
	}
	int n=scc();
	//统计备选解的个数
	int u=0,num=0;
	for(int v=0;v<V;v++){
		if(cmp[v]==n-1){
			u=v;
			num++;
		}
	}
	//检查是否从所有点可达
	memset(used,0,sizeof(used));
	rdfs(u,0);
	for(int v=0;v<V;v++){
		if(!used[v]){
			num=0;
			break;
		}
	}
	cout<<num<<endl;
}
int main()
{
	while (scanf("%d%d",&N,&M)!=EOF)
	{
		for(int i=0;i<M;i++){
			scanf("%d%d",&A[i],&B[i]);
		}
		solve();
	}
	return 0;
}

