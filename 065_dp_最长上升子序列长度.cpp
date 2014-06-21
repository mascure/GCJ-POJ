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
#define inf 10000000
using namespace::std;

int n,K;
int a[MAXN];
//长度为i的最长上升子序列的末尾元素最小值
int dp[MAXN+1];

int main(int argc, const char * argv[])
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i,j;
    cin>>n;
    for (i=0; i<n; i++) {
        cin>>a[i];
    }
    fill(dp, dp+n+1, inf);
    dp[0]=-1;
    int len=0;
    for (i=0; i<n; i++) {
        for (j=1; j<=len; j++) {
            if(a[i]<=dp[j]){
                dp[j]= a [i];
            }
        }
        if (a[i]>dp[len]) {
            dp[++len]=a[i];
        }
    }
    cout<<len<<","<<dp[len]<<endl;
    return 0;
}

