//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#define MAX_N 15
#define MAX_Q 100005
#define MAX_M 5005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//旅行商问题
int n;
//距离
int d[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];
//已经访问过的节点记为S，当前位置为v
int rec(int S,int v){
    if (dp[S][v]>=0) {
        return dp[S][v];
    }
    if (S==(1<<n)-1 && v==0) {
        return dp[S][v]=0;
    }
    int res=inf;
    for (int u=0; u<n; u++) {
        if (!(S>>u&1)) {
            res=min(res, rec(S|1<<u, u)+d[v][u]);
        }
    }
    return dp[S][v]=res;
}
void  solve(){
    memset(dp, -1, sizeof(dp));
    printf("%d\n",rec(0, 0));
}
void solve2(){
    for (int S=0; S<1<<n; S++) {
        fill(dp[S], dp[S]+n, inf);
    }
    dp[(1<<n)-1][0]=0;
    for (int S=(1<<n)-2; S>=0; S--) {
        for (int v=0; v<n; v++) {
            for (int u=0; u<n; u++) {
                if (!(S>>u&1)) {
                    dp[S][v]=min(dp[S][v], dp[S|1<<u][u]+d[v][u]);
                }
            }
        }
    }
    printf("%d\n",dp[0][0]);
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

