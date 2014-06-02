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
#define MAX_V 20005
#define MAX_E 50005
#define inf 10000000
using namespace::std;

struct edge{int from,to,cost;};
edge e[MAX_E];

int d[MAX_V];
int V,E;
int p[MAX_E],r[MAX_E];
int n;
int cost[MAX_V][MAX_V];
void Init(int n){
    for (int i=0; i<n; i++) {
        p[i]=i;
        r[i]=0;
    }
}
int Find(int x){
    if (p[x]!=x) {
        p[x]=Find(p[x]);
    }
    return p[x];
}
void Merge(int a,int b){
    a=Find(a),b=Find(b);
    if (a==b) {
        return;
    }
    if (r[a]<r[b]) {
        p[a]=b;
    }
    else if (r[a]==r[b]){
        p[b]=a;
        r[a]++;
    }
    else
        p[b]=a;
}
bool Same(int a,int b){
    return Find(a)==Find(b);
}
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
int kruskal(){
    Init(V);
    sort(e, e+E, cmp);
    int ans=0;
    for (int i=0; i<E; i++) {
        if (!Same(e[i].from,e[i].to )) {
            Merge(e[i].from, e[i].to);
            ans+=e[i].cost;
        }
    }
    return ans;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    return 0;
}

