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
#define MAX_N 105
#define MAX_Q 100005
#define MAX_M 105
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
#define MAX_X 15
#define MAX_Y 15
#define inf 100000005
using namespace::std;
//边：终点，容量，费用，反向边
struct edge{int to,cap,cost,rev;};

int V;          //定点数
vector<edge> G[MAX_V];
int dist[MAX_V];//最短距离
int prevv[MAX_V],preve[MAX_V];  //最短路中前驱节点和对应的边

//向图中增加一条from到to容量为cap，费用为cost的边
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}

//求从s到t流量为f的最小费用流
//如果不能再增广，则返回-1
int min_cost_flow(int s,int t,int f){
    int res=0;
    while (f>0) {
        //bellman-ford求最短路
        fill(dist, dist+V, inf);
        dist[s]=0;
        bool update=true;
        while (update) {
            update=false;
            for (int v=0; v<V; v++) {
                if (dist[v]==inf) {
                    continue;
                }
                for (int i=0; i<G[v].size(); i++) {
                    edge& e=G[v][i];
                    if (e.cap>0&&dist[e.to]>dist[v]+e.cost) {
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        //不可达
        if (dist[t]==inf) {
            return -1;
        }
        int d=f;
        for (int v=t; v!=s; v=prevv[v]) {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=dist[t]*d;
        for (int v=t; v!=s; v=prevv[v]) {
            edge& e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[e.to][e.rev].cap+=d;
        }
    }
    return res;
}
//N个玩具，M个加工厂
int N,M;
int Z[MAX_N][MAX_M];

void solve(){
    //0~N-1,玩具
    //N~2N-1,0号工厂
    //2N~3N-1,1号工厂
    //MN~(M+1)N-1,M-1号工厂
    int s=N*(M+1),t=s+1;
    V=t+1;
    for (int i=0; i<V; i++) {
        G[i].clear();
    }
    for (int i=0; i<N; i++) {
        add_edge(s, i, 1, 0);
    }
    for (int j=0; j<M; j++) {
        for (int k=0; k<N; k++) {
            add_edge(N+j*N+k, t, 1, 0);
            for (int i=0; i<N; i++) {
                add_edge(i, N+j*N+k, 1, (k+1)*Z[i][j]);
            }
        }
    }
    printf("%.6f\n",(double)min_cost_flow(s, t, N)/N);
}
int main()
{
	//freopen("/Users/mascure/Desktop/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/mascure/Desktop/B-small-attempt1.out", "w", stdout);
    int caseN;
    cin>>caseN;
    while (caseN--) {
        cin>>N>>M;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                scanf("%d",&Z[i][j]);
            }
        }
        solve();
    }
    return 0;
}
