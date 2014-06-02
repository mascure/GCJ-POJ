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
#define inf 100000005
using namespace::std;
typedef long long ll;

int N,M,x[MAX_N];

bool C(int d){
    //第一个放在0的位置
    int last=0;
    for (int i=1; i<M; i++) {
        int now=last+1;
        while (now<N&&x[now]-x[last]<d) {
            now++;
        }
        if (now==N) {
            return false;
        }
        last=now;
    }
    return true;
}
void solve(){
    sort(x, x+N);
    int lb=0,ub=x[N-1];
    while (ub-lb>1) {
        int mid=(lb+ub)/2;
        if (C(mid)) {
            lb=mid;
        }
        else
            ub=mid;
    }
    cout<<lb<<endl;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        scanf("%d",&x[i]);
    }
    solve();
    return 0;
}

