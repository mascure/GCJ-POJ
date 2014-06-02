//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#define MAXN 100
#define MAXM 100
#define MAXK 100000
#define inf 10000000
using namespace::std;

int n,M,m;
//j的i划分
int dp[MAXM+1][MAXN+1];

int main(int argc, const char * argv[])
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i,j;
    while(cin>>n>>m>>M){
        dp[0][0]=1;
        for (i=1; i<=m; i++) {
            for (j=0; j<=n; j++) {
                if (j>=i) {
                    dp[i][j]=(dp[i][j-i]+dp[i-1][j])%M;
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[m][n]<<endl;
    }
    return 0;
}

