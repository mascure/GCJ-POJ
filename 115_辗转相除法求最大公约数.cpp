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
#define MAXN 1005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;

//辗转相处法求最大公约数
int gcd(int a,int b){
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
//求x,y整数对，使得ax+by=gcd(a,b)
int extgcd(int a,int b,int& x,int& y){
    int d=a;
    if (b!=0) {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else{
        x=1,y=0;
    }
    return d;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    
    return 0;
}

