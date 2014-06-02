//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <map>
#define MAX_N 100000005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;

//快速幂运算
typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while (n>0) {
        if (n&1) {
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int x,n;
    while (cin>>x>>n) {
        cout<<mod_pow(x, n, 100007)<<endl;
    }
    return 0;
}

