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
using namespace::std;
typedef long long ll;
//埃式筛法求某个范围内素数个数
int prime[MAX_N];
int nP;  //素数的个数
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
int p[MAX_N],r[MAX_N];
int n;
void Init(int n){
    for (int i=0; i<n; i++) {
        p[i]=i;
        r[i]=0;
    }
}
int Find(int x){
    if (p[x]!=x) {
        p[x]=Find(p[x]);
    }
    return p[x];
}
void Merge(int a,int b){
    a=Find(a),b=Find(b);
    if (a==b) {
        return;
    }
    if (r[a]<r[b]) {
        p[a]=b;
    }
    else if (r[a]==r[b]){
        p[b]=a;
        r[a]++;
    }
    else
        p[b]=a;
}
ll A,B,P;
void sovle(){
    int len=(int)(B-A+1);
    nP=sieve(1000000);
    Init(len);  //初始化并查集
    
    for (int i=0; i<nP; i++) {
        //对不小于P的素数进行处理
        if (prime[i]>=P) {
            ll start= (A+prime[i]-1)/prime[i]* prime[i];
            ll end=B/prime[i]*prime[i];
            for (ll j=start; j<=end; j+=prime[i]) {
                Merge(int(start-A), int(j-A));
            }
        }
    }
    int res=0;
    for (ll i=A; i<=B; i++) {
        if (Find((int)(i-A))==i-A) {
            res++;
        }
    }
    cout<<res<<endl;
}
int main()
{
	freopen("/Users/mascure/Desktop/B-large-practice.in", "r", stdin);
	freopen("/Users/mascure/Desktop/B-large-practice.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        scanf("%lld%lld%lld",&A,&B,&P);
        cout<<"Case #"<<i<<": ";
        sovle();
    }
    return 0;
}
