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
#define MAX_N 50005
#define MAX_Q 100005
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;//存储线段树的全局数组
int n,dat[2*MAX_N-1];
//初始化，简单起见，将数组扩展到2的幂
void rmq_init(int n_){
    n=1;
    while (n<n_) {
        n*=2;
    }
    for (int i=0; i<n; i++) {
        dat[i]=INT_MAX;
    }
}
//把第k个值更新为a
void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while (k>0) {
        k=(k-1)/2;
        dat[k]=min(dat[2*k+1], dat[2*k+2]);
    }
}
//求[a,b)的最小值
//k是节点的编号，l,r表示这个节点对应的是[l,r)区间
int query(int a,int b,int k,int l,int r){
    //[a,b)与[l,r)不相交
    if (a>=r||b<=l) {
        return INT_MAX;
    }
    //包含
    if (a<=l&&b>=r) {
        return dat[k];
    }
    //部分相交
    int v1=query(a, b, k*2+1, l, (l+r)/2);
    int v2=query(a, b, k*2+2, (l+r)/2, r);
    return min(v1, v2);
}
int N,M;
int s[MAX_N],t[MAX_N];

int dp[MAX_N+1];
void solve(){
    rmq_init(N+1);
    fill(dp, dp+N+1, inf);
    dp[1]=0;
    update(1, 0);
    for (int i=0; i<M; i++) {
        int v=min(dp[t[i]],query(s[i], t[i]+1, 0, 0, n)+1);
        dp[t[i]]=v;
        update(t[i], v);
    }
    cout<<dp[N]<<endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin>>N>>M) {
        for (int i=0; i<M; i++) {
            scanf("%d%d",&s[i],&t[i]);
        }
        solve();
    }
    return 0;
}
