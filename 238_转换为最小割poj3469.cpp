#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#define MAX_N 20005
#define MAX_Q 100005
#define MAX_M 200005
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
#define MAX_X 15
#define MAX_Y 15
#define inf 1000005
using namespace::std;
typedef long long ll;
/*
 最大流算法：Dinic算法
 */
//用于表示边的结构体（终点，容量，反向边）
struct edge{
    int to,cap,rev;
};
vector<edge> G[MAX_V];  //图的邻接表表示
int level[MAX_V];       //顶点到源点得距离编号
int iter[MAX_V];        //当前弧，在其之前的边已经没有用了
//向图中增加一条from到to得容量为cap的边
void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while (!que.empty()) {
        int v=que.front();que.pop();
        for (int i=0; i<G[v].size(); i++) {
            edge& e=G[v][i];
            if (e.cap>0&&level[e.to]<0) {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
//通过dfs寻找增广路
int dfs(int v,int t,int f){
    if (v==t) {
        return f;
    }
    for (int &i=iter[v]; i<G[v].size(); i++) {
        edge& e=G[v][i];
        if (e.cap>0&&level[e.to]>level[v]) {
            int d=dfs(e.to, t, min(f,e.cap));
            if (d>0) {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
//求解从s到t得最大流
int max_flow(int s,int t){
    int flow=0;
    for (; ; ) {
        bfs(s);
        if (level[t]<0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f=dfs(s, t, inf))>0) {
            flow+=f;
        }
    }
}
int N,M;
int A[MAX_N],B[MAX_N];
int a[MAX_M],b[MAX_M],w[MAX_M];
void solve(){
    int s=N,t=s+1;
    
    //在各个核上执行所产生的费用
    for (int i=0; i<N; i++) {
        add_edge(i, t, A[i]);
        add_edge(s, i, B[i]);
    }
    //在不同核上执行所产生的费用
    for (int i=0; i<M; i++) {
        add_edge(a[i]-1, b[i]-1, w[i]);
        add_edge(b[i]-1, a[i]-1, w[i]);
    }
    cout<<max_flow(s, t)<<endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    while (cin>>N>>M){
        for (int i=0; i<N; i++) {
            scanf("%d%d",&A[i],&B[i]);
        }
        for (int i=0; i<M; i++) {
            scanf("%d%d%d",&a[i],&b[i],&w[i]);
        }
        solve();
    }
    return 0;
}
