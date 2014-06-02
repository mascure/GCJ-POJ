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
#include <map>
#define MAX_N 1005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;
typedef long long ll;

//A下标从1开始
int P,Q,A[MAX_Q+2];
//表示A[i]到A[j]范围内囚犯释放（不含两端），所需最少的金币
int dp[MAX_Q+1][MAX_Q+2];
void solve(){
    A[0]=0;
    A[Q+1]=P+1;
    for (int i=0; i<=Q; i++) {
        dp[i][i+1]=0;
    }
    for (int w=2; w<=Q+1; w++) {
        for (int i=0; i+w<=Q+1; i++) {
            int j=i+w,t=inf;
            for (int k=i+1; k<j; k++) {
                t=min(t,dp[i][k]+dp[k][j]);
            }
            dp[i][j]=t+A[j]-A[i]-2;
        }
    }
    cout<<dp[0][Q+1]<<endl;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>P>>Q) {
        for (int i=0; i<Q; i++) {
            scanf("%d",&A[i+1]);
        }
        solve();
    }
    return 0;
}

