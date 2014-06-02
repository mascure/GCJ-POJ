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
#define MAX_N 10005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

int n,k;
int v[MAX_N],w[MAX_N];

bool C(double ave){
    double t[MAX_N];
    for (int i=0; i<n; i++) {
        t[i]=v[i]-ave*w[i];
    }
    sort(t, t+n);
    //取后k个
    double sum=0;
    for (int i=n-1; n-i<=k; i--) {
        sum+=t[i];
        if (sum<0) {
            return false;
        }
    }
    return true;
}
void solve(){
    double lb=0,ub=inf;
    int total=100;
    while (total--) {
        double mid=(lb+ub)/2;
        if (C(mid)) {
            lb=mid;
        }
        else
            ub=mid;
    }
    printf("%.2f\n",lb);
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        scanf("%d%d",&w[i],&v[i]);
    }
    solve();
    return 0;
}

