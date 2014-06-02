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
#define MAX_N 5005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

//O(N^3) Time Limit Exceeded
int N;
int a[MAX_N];

void solve(){
    int resM=inf,resK=0;
    for (int i=1; i<=N; i++) {
        int now=0;
        //复制一份
        int tmp[MAX_N];
        for (int j=0; j<N; j++) {
            tmp[j]=a[j];
        }
        //从第一个元素开始
        for (int j=0; j+i-1<N; j++) {
            if (tmp[j]) {
                now++;
                for (int k=0; k<i;k++ ) {
                    tmp[j+k]=!tmp[j+k];
                }
            }
        }
        bool remain=true;
        for (int j=N-i+1; j<N; j++) {
            if (tmp[j]) {
                remain=false;
                break;
            }
        }
        if (remain&&now<resM) {
            resM=now;resK=i;
        }
    }
    cout<<resK<<" "<<resM<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while(cin>>N){
        for (int i=0; i<N; i++) {
            getchar();
            char ch;
            scanf("%c",&ch);
            if (ch=='F') {
                a[i]=0;
            }
            else a[i]=1;
        }
        solve();
    }
    return 0;
}

