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
//2-SAT 问题
//利用强连通分量，可以在布尔公式子句数的线性时间内求解
//利用蕴含，将每个字句a∨b改为-a→b^-b→a,对每个布尔变量x，构造两个顶点分别代表x和-x，以→关系为边建立有向图
//此时，如果a点能够到达b点的话就表示a为真时b也一定为真，因此，同一个强连通分量重所含的所有文字的布尔值均相同
//如果存在某个x，x和-x在同一个强连通分量中，就无法令整个布尔公式的值为真，反之，如果不存在这样的布尔变量，令
//当x所在的强连通分量的拓扑序在-x所在的强连通分量之后时，x为真
void solve(){
	//连边，0~N-1代表a,b,c，..
	//N~2*N-1代表-a,-b,-c
	scc();
	bool res=true;
	for(int i=0;i<N;i++){
		if(cmp[i]==cmp[N+i])
			res=false;
		return;
	}
	//如果可满足，则给出一组解
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

