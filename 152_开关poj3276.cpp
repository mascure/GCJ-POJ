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

//O(N^2)
int N;
int a[MAX_N];

void solve(){
    int resM=inf,resK=0;
    for (int i=1; i<=N; i++) {
        int now=0;
        //f[i],区间[i,i+K-1]进行了反转则为1，否则为0；sum标记i-k+1到i-1反转次数
        int f[MAX_N],sum=0;
        fill(f, f+N, 0);
        //复制一份
        int tmp[MAX_N];
        for (int j=0; j<N; j++) {
            tmp[j]=a[j];
        }
        //从第一个元素开始
        for (int j=0; j+i-1<N; j++) {
            //当前j面向后方
            if ((sum%2==0&&tmp[j])||(sum%2==1&&tmp[j]==0)) {
                now++;
                f[j]=1;
            }
            if (j-i+1<0) {
                sum=sum+f[j];
            }
            else
                sum=sum-f[j-i+1]+f[j];
        }
        bool remain=true;
        for (int j=N-i+1; j<N; j++) {
            if ((sum%2==0&&tmp[j])||(sum%2==1&&tmp[j]==0)) {
                remain=false;
                break;
            }
            if (j-i+1>=0) {
                sum-=f[j-i+1];
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

