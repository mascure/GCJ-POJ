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
const int M=10007;
mat mul(mat& A, mat& B){
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
int N;
void solve(){
    mat A(3,vec(3));
    A[0][0]=2;A[0][1]=1;A[0][2]=0;
    A[1][0]=2;A[1][1]=2;A[1][2]=2;
    A[2][0]=0;A[2][1]=1;A[2][2]=2;
    A = pow(A, N);
    printf("%d\n",A[0][0]);
}
int main()
{
    //freopen("/Users/mascure/Desktop/D-large.in", "r", stdin);
    //freopen("/Users/mascure/Desktop/D-large.out", "w", stdout);
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int T;
    cin>>T;
    while (T--) {
        cin>>N;
        solve();
    }
    return 0;
}

