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
#define MAX_N 1000005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

int p;
int a[MAX_N];

void solve(){
    int res=p;
    set<int> k;
    for (int i=0; i<p; i++) {
        k.insert(a[i]);
    }
    int n=k.size();
    int s=0,t=0,num=0;
    map<int, int> q;
    for (; ; ) {
        while (t<p&&num<n) {
            if (q[a[t++]]++==0) {
                num++;
            }
        }
        if (num<n) {
            break;
        }
        res=min(res, t-s);
        if(--q[a[s++]]==0)
            num--;
    }
    cout<<res<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    cin>>p;
    for (int i=0; i<p; i++) {
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}

