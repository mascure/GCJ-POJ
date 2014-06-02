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
#define MAX_V 1000
#define MAX_E 100000
#define inf 10000000
using namespace::std;

struct edge{int from,to,cost;};
edge e[MAX_E];

int d[MAX_V];
int V,E;
//邻接阵实现
int cost[MAX_V][MAX_V];
bool used[MAX_V];
//O(v*v)
void dijkstra(int s){
    int i;
    fill(d, d+V, inf);
    fill(used, used+V, false);
    d[s]=0;
    while (true) {
        int p=-1;
        for (i=0; i<V; i++) {
            if (!used[i]&&(p==-1||d[i]<d[p])) {
                p=i;
            }
        }
        if (p==-1) {
            break;
        }
        used[p]=true;
        for (i=0; i<V; i++) {
                d[i]=min(d[i],d[p]+cost[p][i]);
        }
    }
}
//边表+优先队列实现 O(E*logv)
typedef pair<int, int> P;//first表示距离，second表示to
struct Edge{int to, cost;};
vector<Edge> G[MAX_V];
void dijkstra2(int s){
    //按照first从小到大排列
    priority_queue<P,vector<P>,greater<P> > q;
    fill(d, d+V, inf);
    fill(used, used+V, false);
    d[s]=0;
    q.push(P(0,s));
    while (!q.empty()) {
        P p=q.top();q.pop();
        if (p.first>d[p.second]) {
            continue;
        }
        for (int u=0; u<G[p.first].size(); u++) {
            Edge e=G[p.first][u];
            if (d[e.to]>d[p.first]+e.cost) {
                d[e.to]=d[p.first]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
}
//带前驱节点以记录最短路径上的节点
int pre[MAX_V];
void dijkstra(int s){
    int i;
    fill(d, d+V, inf);
    fill(used, used+V, false);
    fill(pre,pre+V,-1);
    d[s]=0;
    while (true) {
        int p=-1;
        for (i=0; i<V; i++) {
            if (!used[i]&&(p==-1||d[i]<d[p])) {
                p=i;
            }
        }
        if (p==-1) {
            break;
        }
        used[p]=true;
        for (i=0; i<V; i++) {
            if (d[i]>d[p]+cost[p][i]) {
                pre[i]=p;
            }
        }
    }
}


int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

