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
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
int M;
//n行m列
int n,m;
bool color[MAX_N][MAX_M];//false：白，true:黑
//现在查看的时i,j格子，used表示那些格子已经被覆盖过
int rec(int i,int j,bool used[MAX_N][MAX_M]){
    //到下一行
    if (j==m) {
        return rec(i+1, 0, used);
    }
    //已经覆盖了所有行
    if (i==m) {
        return 1;
    }
    //无法在[i,j]上放置
    if (used[i][j]||color[i][j]) {
        return rec(i, j+1, used);
    }
    //尝试2种放法
    int res=0;
    used[i][j]=true;
    if (j+1<m&&!used[i][j+1]&&!color[i][j+1]) {
        used[i][j+1]=true;
        res+=rec(i, j+1, used);
        used[i][j+1]=false;
    }
    if (i+1<n&&!used[i+1][j]&&!color[i+1][j]) {
        used[i+1][j]=true;
        res+=rec(i, j+1, used);
        used[i+1][j]=false;
    }
    used[i][j]=false;
    return res%M;
}
void solve(){
    bool used[MAX_N][MAX_M];
    memset(used, 0, sizeof(used));
    printf("%d\n",rec(0, 0, used));
}
int dp[2][1<<MAX_M];//dp数组，循环利用
//NOT COMPLETE!
void solve2(){
    int *crt=dp[0],*next=dp[1];
    crt[0]=1;
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            for (int used=0; used<1<<m;used++) {
                if (used>>j&1||color[i][j]) {
                    next[used]=crt[used|~(1<<j)];
                }
            }
        }
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

