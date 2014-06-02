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
#define MAX_M 5005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
const int ST_SIZE=(1<<18)-1;
int n,m;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];
int nums[MAX_N];//对A排序之后的结果
vector<int> dat[ST_SIZE];
//构建线段树
//k是节点编号，区间[l,r)
void init(int k,int l,int r){
    if (r-l==1) {
        dat[k].push_back(A[l]);
    }
    else{
        int lch=2*k+1,rch=2*k+2;
        init(lch, l, (l+r)/2);
        init(rch, (l+r)/2, r);
        dat[k].resize(r-l);
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }
}
//计算[i,j)中不超过x的数的个数
//k是节点编号，和区间[l,r)对应
int query(int i,int j,int x,int k,int l,int r){
    //不相交
    if (l>=j||i>=r) {
        return 0;
    }
    //完全包含
    else if(i<=l&&r<=j){
        return upper_bound(dat[k].begin(), dat[k].end(), x)-dat[k].begin();
    }
    else{
        int lc=query(i, j, x, 2*k+1, l, (l+r)/2);
        int rc=query(i, j, x, 2*k+2, (l+r)/2, r);
        return lc+rc;
    }
}
void  solve(){
    for (int i=0; i<n; i++) {
        nums[i]=A[i];
    }
    sort(nums, nums+n);
    
    init(0, 0, n);
    
    for (int i=0; i<m; i++) {
        int l=I[i],r=J[i]+1,k=K[i];
        int lb=-1,ub=n-1;
        while (ub-lb>1) {
            int md=(lb+ub)/2;
            int c=query(l, r, nums[md], 0, 0, n);
            if (c>=k) {
                ub=md;
            }
            else
                lb=md;
        }
        printf("%d\n",nums[ub]);
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>n>>m) {
        for (int i=0; i<n; i++) {
            scanf("%d",&A[i]);
        }
        for (int i=0; i<m; i++) {
            scanf("%d%d%d",&I[i],&J[i],&K[i]);
            I[i]--;J[i]--;
        }
        solve();
    }
    return 0;
}

