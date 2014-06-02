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
#define MAX_N 1005
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//[1,n],下标从1开始
int bit[MAX_N+1],n;
//求1到i的和：不断把当前位置i的值加到结果中，并将最低位的1去掉，直到i为0
int sum(int i){
    int s=0;
    while (i>0) {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
//第i项加x：不断把当前位置i的值增加x，并把i的二进制最低位1对应的幂加到i上
void add(int i,int x){
    while (i<=n) {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

