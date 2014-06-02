#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#define MAX_N 1000005
#define MAX_Q 100005
#define MAX_M 105
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
//#define MAX_K 25
#define MAX_X 15
#define MAX_Y 15
#define inf 100000005
#define MOD 1000000007
using namespace::std;
typedef long long ll;
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
//当a，m互质时，对ax=1 MOD m 求x
int mod_inverse(int a,int m){
    int x,y;
    extgcd(a, m, x, y);
    return (m+x%m)%m;
}
//m=p1^e1 * p2^e2 * ... * pn^en
//欧拉函数：ø(m)=m * (p1-1)/p1 * (p2-1)/p2 * .. * (pn-1)/pn
//ø(m)表示不大于m且与m互质的数的个数
//求欧拉函数值
int euler_phi(int n){
    int res=n;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            res = res / i*(i-1);
            for (; n%i==0; n/=i);
        }
    }
    if (n!=1) {
        res=res/n*(n-1);
    }
    return res;
}
//快速幂运算
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while (n>0) {
        if (n&1) {
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
//m是质数
ll mod_inverse2(ll a,ll m){
    return mod_pow(a, m-2, m);
}
//m不是质数
ll mod_inverse3(ll a,ll m){
    return mod_pow(a, euler_phi(m)-1, m);
}
int euler[MAX_N];
//O(MAX_N)时间筛出欧拉函数值的表
void euler_phi2(){
    for (int i=0; i<MAX_N; i++) {
        euler[i]=i;
    }
    for (int i=2; i<MAX_N; i++) {
        if (euler[i]==i) {
            for (int j=i; j<MAX_N; j+=i) {
                euler[j]=euler[j]/i*(i-1);
            }
        }
    }
}
int N;
void sovle(){
    vector<int> f;
    f.resize(N);
    f[0]=f[1]=1;
    for (int i=2; i<=N; i++) {
        f[i]=0;
        for (int j=0; j<i; j++) {
            f[i]+=f[j]*f[i-j-1];
            f[j]%=MOD;
        }
    }
    cout<<f[N]<<endl;
}
int main()
{
	//freopen("/Users/mascure/Desktop/B-large-practice.in", "r", stdin);
	//freopen("/Users/mascure/Desktop/B-large-practice.out", "w", stdout);
    cout<<(-15)%10<<endl;
    return 0;
}
