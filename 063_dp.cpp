//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#define MAXN 100
#define MAXK 100000
using namespace::std;

int n,K;
int a[MAXN],m[MAXN];
int dp[MAXN+1][MAXK+1];

int main(int argc, const char * argv[])
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i,j;
    cin>>n;
    for (i=0; i<n; i++) {
        cin>>a[i]>>m[i];
    }
    cin>>K;
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    for (i=0; i<n; i++) {
        for (j=0; j<=K; j++) {
            if(dp[i][j]>=0)dp[i+1][j]=m[i];
            else if (j<a[i]||dp[i+1][j-a[i]]<=0)dp[i+1][j]=-1;
            else
                dp[i+1][j]=dp[i+1][j-a[i]]-1;
        }
    }
    if(dp[n][K]>=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

