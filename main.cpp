#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_N 105
#define MAX_M 20;
typedef long long ll;
using namespace std;
//辗转相处法求最大公约数
ll gcd(ll a,ll b){
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
int a[MAX_N];
int n,m;
void solve(){
    ll res=0;
    for (int i=1; i<(1<<m); i++) {
        //求i的二进制中1的个数
        int num=0;
        for (int j=i; j!=0; j>>=1) {
            num+=j&1;
        }
        ll lcm=1;
        for (int j=0; j<m; j++) {
            if (i>>j & 1) {
                lcm=lcm/gcd(lcm,a[j])*a[j];
                if (lcm>n) {
                    break;
                }
            }
        }
        if (num%2==0) {
            res-=n/lcm;
        }
        else res+=n/lcm;
    }
    cout<<res<<endl;
}
int main() {
    
    return 0;
}