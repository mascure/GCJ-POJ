//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <string>
#include <set>
#include <map>
#define MAX_N 100000005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;

//判断素数
bool is_prime(int n){
    for (int i=2;i*i<=n; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return n!=1;
}
//约数枚举
vector<int> divisor(int n){
    vector<int> ans;
    for (int i=1; i*i<=n; i++) {
        if (n%i==0) {
            ans.push_back(i);
            if (i!=n/i) {
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
//整数分解
map<int,int> prime_factor(int n){
    map<int, int> ans;
    for (int i=2; i*i<=n; i++) {
        while (n%i==0) {
            ans[i]++;
            n/=i;
        }
    }
    if (n!=1) {
        ans[n]=1;
    }
    return ans;
}
//埃式筛法求某个范围内素数个数
int prime[MAX_N];
bool isprime[MAX_N+1];
int sieve(int n){
    int p=0;
    fill(isprime, isprime+MAX_N+1, true);
    isprime[0]=isprime[1]=false;
    for (int i=2; i<=n; i++) {
        if (isprime[i]) {
            prime[p++]=i;
            for (int k=2; k*i<=n; k++) {
                isprime[k*i]=false;
            }
        }
    }
    return p;
}
#define MAX_SQRT_B 1000000
#define MAX_L 1000000
//区间[a,b)内素数的个数，筛法
//a<b<=10^12 b-a<=10^6
typedef long long ll;
bool is_prime_small[MAX_SQRT_B];
bool is_prime2[MAX_L];
void segment_sieve(ll a,ll b){
    for (int i=0; (ll)i*i<b; i++) {
        is_prime_small[i]=true;
    }
    for (int i=0; (ll)i<b-a; i++) {
        is_prime2[i]=true;
    }
    for (int i=2; (ll)i*i<b; i++) {
        if (is_prime_small[i]) {
            //筛[2,sqrt(b))
            for (int j=2*i; (ll)j*j<b; j+=i) {
                is_prime_small[j]=false;
            }
            //筛[a,b)
            for (ll j=max(2ll,(a+i-1)/i)*i; j<b; j+=i) {
                is_prime2[j-a]=false;
            }
        }
    }
}
int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int n;
    while (cin>>n) {
        cout<<sieve(n)<<endl;
    }
    return 0;
}

