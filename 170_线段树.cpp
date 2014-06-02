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
#include <stdio.h>
#include <sstream>
#define MAX_N 505
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//存储线段树的全局数组
int n,dat[2*MAX_N-1];
//初始化，简单起见，将数组扩展到2的幂
void init(int n_){
    n=1;
    while (n<n_) {
        n*=2;
    }
    for (int i=0; i<n; i++) {
        dat[i]=INT_MAX;
    }
}
//把第k个值更新为a
void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while (k>0) {
        k=(k-1)/2;
        dat[k]=min(dat[2*k+1], dat[2*k+2]);
    }
}
//求[a,b)的最小值
//k是节点的编号，l,r表示这个节点对应的是[l,r)区间
int query(int a,int b,int k,int l,int r){
    //[a,b)与[l,r)不相交
    if (a>=r||b<=l) {
        return INT_MAX;
    }
    //包含
    if (a<=l&&b>=r) {
        return dat[k];
    }
    //部分相交
    int v1=query(a, b, k*2+1, l, (l+r)/2);
    int v2=query(a, b, k*2+2, (l+r)/2, r);
    return min(v1, v2);
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    cout<<INT_MAX<<endl;
    return 0;
}

