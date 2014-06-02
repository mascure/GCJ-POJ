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
#define MAX_N 8
#define MAX_Q 100005
#define MAX_M 30
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//n:票的张数，m:城市个数，从a到b
int n,m,a,b;
int t[MAX_N];
int d[MAX_M][MAX_M];//图的邻接阵表示,-1表示没有边
//dp[S][v]:=到达剩下的车票为S，并且现在在城市v的状态的最小花费
double dp[1<<MAX_N][MAX_M];
void solve(){
    for (int i=0; i<n; i++) {
        fill(dp[i], dp[i]+m, inf);
    }
    dp[(1<<n)-1][a-1]=0;
    double res=inf;
    for (int S=(1<<n)-1; S>=0; S--) {
        res=min(res, dp[S][b-1]);
        for (int v=0; v<m; v++) {
            for (int i=0; i<n; i++) {
                if (S&1<<i) {
                    for (int u=0; u<m; u++) {
                        if (d[v][u]>0) {
                            dp[S&~(1<<i)][u]=min(dp[S&~(1<<i)][u], dp[S][v]+(double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }
    if (res==inf) {
        printf("Impossible\n");
    }
    else
        printf("%.3f\n",res);
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

