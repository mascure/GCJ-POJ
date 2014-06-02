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
//O(v*e)
void bellman_ford_shortest_path(int s){
    int i;
    for (i=0; i<V; i++) {
        d[i]=inf;
    }
    d[s]=0;
    while (true) {
        bool update=false;
        for (i=0; i<E; i++) {
            int from=e[i].from,to=e[i].to;
            if (d[from]!=inf&&d[to]>d[from]+e[i].cost) {
                d[to]=d[from]+e[i].cost;
                update=true;
            }
        }
        if (!update) {
            break;
        }
    }
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    return 0;
}

