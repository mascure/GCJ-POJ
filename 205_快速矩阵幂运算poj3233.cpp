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
#include <math.h>
#define MAX_N 15
#define MAX_Q 100005
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
int M;
mat mul(mat& A, mat& B){
    //A的行数，B的列数
    mat C(A.size(),vec(B[0].size()));
    for (int i=0; i<A.size(); i++) {
        for (int k=0; k<B.size(); k++) {
            for (int j=0; j<B[0].size(); j++) {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}
//计算A^n
mat pow(mat A,ll n){
    mat B(A.size(),vec(A[0].size()));
    for (int i=0; i<A.size(); i++) {
        B[i][i]=1;
    }
    while (n>0) {
        if (n&1) {
            B=mul(B, A);
        }
        A=mul(A, A);
        n>>=1;
    }
    return B;
}
int n,k;
mat A;
void solve(){
    mat B(n*2,vec(n*2));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            B[i][j]=A[i][j];
        }
        B[i+n][i]=B[i+n][i+n]=1;
    }
    B=pow(B, k+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a=B[n+i][j]%M;
            if (i==j) {
                a=(a+M-1)%M;
            }
            printf("%d%c",a,j==n-1?'\n':' ');
        }
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>n>>k>>M) {
        A.resize(n, vec(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>A[i][j];
            }
        }
        solve();
    }
    return 0;
}

