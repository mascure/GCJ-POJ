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
int a[MAX_N];

void solve(){
    int res=n+1;
    int s=0,t=0,sum=0;
    for (; ; ) {
        while (t<n&&sum<S) {
            sum+=a[t++];
        }
        if (sum<S) {
            break;
        }
        res=min(res, t-s);
        sum-=a[s];
        s++;
    }
    if (res>n) {
        res=0;
    }
    cout<<res<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int caseN;
    cin>>caseN;
    while (caseN--) {
        cin>>n>>S;
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}

