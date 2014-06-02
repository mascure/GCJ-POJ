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
#define MAX_N 100005
#define MAX_Q 100005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
const int DAT_SIZE=(1<<18)-1;
int N,Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q],R[MAX_Q],X[MAX_Q];
//线段树，data表示的是在本区间所有元素上加的值，这个值不会向下传，求和用区间长*data；datb表示在在部分元素上相加的值的和，这种情况x会向下传；求和只有当包含本区间时，用上，否则，只计算data部分
ll data[DAT_SIZE],datb[DAT_SIZE];
//对区间[a,b)同时加上x
//k是节点编号，对应的区间是[l,r)
void add(int a,int b,int x,int k,int l,int r){
    if (a<=l&&r<=b) {
        data[k]+=x;
    }
    else if (l<b&&a<r){
        datb[k]+=(min(b, r)-max(a, l))*x;
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
    }
}
//计算[a,b)的和
//k是节点编号，[l,r)是对应区间
ll sum(int a,int b,int k,int l,int r){
    //不相交
    if (b<=l||a>=r) {
        return 0;
    }
    //完全包含
    else if (a<=l&&r<=b) {
        return data[k]*(r-l)+datb[k];
    }
    else{
        ll res=(min(b, r)-max(a, l))*data[k];
        res+=sum(a, b, 2*k+1, l, (l+r)/2);
        res+=sum(a, b, 2*k+2, (l+r)/2, r);
        return res;
    }
}
void solve(){
    for (int i=0; i<N; i++) {
        add(i, i+1, A[i], 0, 0, N);
    }
    for (int i=0; i<Q; i++) {
        if (T[i]=='C') {
            add(L[i], R[i]+1, X[i], 0, 0, N);
        }
        else{
            printf("%lld\n",sum(L[i], R[i]+1, 0, 0, N));
        }
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>N>>Q) {
        for (int i=0; i<N; i++) {
            scanf("%d",&A[i]);
        }
        for (int i=0; i<Q; i++) {
            getchar();
            scanf("%c%d%d",&T[i],&L[i],&R[i]);
            L[i]--;R[i]--;
            if (T[i]=='C') {
                scanf("%d",&X[i]);
            }
        }
        solve();
    }
    return 0;
}

