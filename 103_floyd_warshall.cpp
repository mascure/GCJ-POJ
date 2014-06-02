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
//floyd-warshall
//d[i][j]表示变ij的权值
int d[MAX_V][MAX_V];
void floyd_warshall(){
    for (int k=0; k<V; k++) {
        for (int i; i<V; i++) {
            for (int j=0; j<V; j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    return 0;
}

