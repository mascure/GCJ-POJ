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
#include <string>
#include <stdio.h>
#include <cmath>
#include <sstream>
#define MAX_N 100005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

int n,S;
int a[MAX_N],sum[MAX_N];

void solve(){
    sum[0]=0;
    for (int i=0; i<n; i++) {
        sum[i+1]=sum[i]+a[i];
    }
    //解不存在
    if (sum[n]<S) {
        cout<<0<<endl;
    }
    int res=n;
    for (int s=0; sum[s]+S<=sum[n]; s++) {
        int t=lower_bound(sum+s, sum+n, sum[s]+S)-sum;
        res=min(res,t-s);
    }
    cout<<res<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    cin>>n>>S;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}

