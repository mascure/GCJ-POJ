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
#define MAX_N 4005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

int N;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N];
int CD[MAX_N*MAX_N];

void solve(){
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            CD[i*N+j]=C[i]+D[j];
        }
    }
    sort(CD, CD+N*N);
    ll res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int cd=-(A[i]+B[j]);
            res+=upper_bound(CD, CD+N*N, cd)-lower_bound(CD, CD+N*N, cd);
        }
    }
    cout<<res<<endl;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while(cin>>N){
        for (int i=0; i<N; i++) {
            scanf("%d",&A[i]);
            scanf("%d",&B[i]);
            scanf("%d",&C[i]);
            scanf("%d",&D[i]);
        }
        solve();
    }
    return 0;
}

