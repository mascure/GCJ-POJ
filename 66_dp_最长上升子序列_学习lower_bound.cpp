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
    int i;
    cin>>n;
    for (i=0; i<n; i++) {
        cin>>a[i];
    }
    fill(dp, dp+n, inf);
    for (i=0; i<n; i++) {
        *lower_bound(dp, dp+n, a[i])=a[i];
    }
    cout<<lower_bound(dp, dp+n, inf)-dp<<endl;
    return 0;
}

