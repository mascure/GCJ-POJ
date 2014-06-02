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
#define MAX_N 105
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

const double g=10.0;
int N,H,R,T;
double y[MAX_N];

double calc(int T){
    if (T<0) {
        return H;
    }
    double t=sqrt(2*H/g);
    int k=(int)(T/t);
    if (k%2==0) {
        double d=T-k*t;
        return H-g*d*d/2;
    }
    else{
        double d=k*t+t-T;
        return H-g*d*d/2;
    }
}
void solve(){
    for (int i=0; i<N; i++) {
        y[i]=calc(T-i);
    }
    sort(y, y+N);
    for (int i=0; i<N; i++) {
        printf("%.2f%c",y[i]+2*R*i/100.0,i+1==N?'\n':' ');
    }
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int caseN;
    cin>>caseN;
    while(caseN--){
        cin>>N>>H>>R>>T;
        solve();
    }
    return 0;
}

