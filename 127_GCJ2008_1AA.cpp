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
#define MAX_N 1005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;
typedef long long ll;

int n;
int v1[MAX_N],v2[MAX_N];
void solve(){
    sort(v1, v1+n);
    sort(v2, v2+n);
    ll res=0;
    for (int i=0; i<n; i++) {
        res+=(ll)v1[i]*v2[n-1-i];
    }
    cout<<res<<endl;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            scanf("%d",&v1[i]);
        }
        for (int i=0; i<n; i++) {
            scanf("%d",&v2[i]);
        }
        solve();
    }
    return 0;
}

