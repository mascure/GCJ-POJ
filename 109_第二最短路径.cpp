//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <set>
#define MAXN 1005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;

struct edge{int from,to,cost;};
edge e[MAX_E];

int E,V;
int d[MAX_V],d2[MAX_V];
//边表+优先队列实现 O(E*logv)
typedef pair<int, int> P;//first表示距离，second表示to
struct Edge{
public:
    int to, cost;
    Edge(int to,int cost){
        this->to=to;
        this->cost=cost;
    }
};
vector<Edge> G[MAX_V];
void dijkstra2(int s){
    //按照first从小到大排列
    priority_queue<P,vector<P>,greater<P> > q;
    fill(d, d+V, inf);
    fill(d2, d2+V, inf);
    d[s]=0;    q.push(P(0,s));
    while (!q.empty()) {
        P p=q.top();q.pop();
        int v=p.second,dis=p.first;
        if (p.first>d2[v]) {
            continue;
        }
        for (int u=0; u<G[v].size(); u++) {
            Edge e=G[v][u];
            int dd=dis+e.cost;
            if (d[e.to]>dd) {
                swap(d[e.to], dd);
                q.push(P(d[e.to],e.to));
            }
            if (d2[e.to]>dd&&d[e.to]<dd) {
                d2[e.to]=dd;
                q.push(P(d2[e.to],e.to));
            }
        }
    }
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i;
    while (scanf("%d%d",&V,&E)!=EOF) {
        for (i=0; i<V; i++) {
            G[i].clear();
        }
        for (i=0; i<E; i++) {
            int a,b,dis;
            scanf("%d%d%d",&a,&b,&dis);
            a--;b--;
            Edge ab(b,dis),ba(a,dis);
            G[a].push_back(ab);
            G[b].push_back(ba);
        }
        dijkstra2(0);
        cout<<d2[V-1]<<endl;
    }
    return 0;
}

