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
#include <cmath>
#include <sstream>
#define MAX_N 40
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//超大背包问题，n≤40,wi,vi≤10^15
int n;
ll W;
ll w[MAX_N],v[MAX_N];
pair<ll, ll> ps[1<<(MAX_N/2)];

void solve(){
    //枚举前半部分
    int n1=n/2;
    int n2=n-n1;
    for (int i=0; i< 1<<n1; i++) {
        ll w2=0,v2=0;
        for (int j=0; j<n1; j++) {
            if (i>>j&1) {
                w2+=w[j];
                v2+=v[j];
            }
        }
        ps[i]=make_pair(w2, v2);
    }
    sort(ps, ps+ (1<<n1));
    int m=1;
    for (int i=0; i< 1<<n1; i++) {
        if (ps[m-1].second<ps[i].second) {
            ps[m++]=ps[i];
        }
    }
    //枚举后半部分并求解
    ll res=0;
    for (int i=0; i< 1<<n2; i++) {
        ll w2=0,v2=0;
        for (int j=0; j<n2; j++) {
            if (i>>j&1) {
                w2+=w[n1+j];
                v2+=v[n1+j];
            }
        }
        if (w2<=W) {
            ll v=(upper_bound(ps, ps+m, make_pair(W-w2, (ll)inf))-1)->second;
            res=max(res, v2+v);
        }
    }
    cout<<res<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while(cin>>n>>W){
        for (int i=0; i<n; i++) {
            scanf("%lld%lld",&w[i],&v[i]);
        }
        solve();
    }
    return 0;
}

