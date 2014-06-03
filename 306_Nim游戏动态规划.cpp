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
#define MAX_K 105
#define MAX_X 10005
typedef long long ll;
using namespace std;
//输入
int X,K,A[MAX_K];
//动态规划所用的数组
bool win[MAX_X+1];
void solve(){
    win[0]=false;
    for(int j=1;j<=X;j++){
        win[j]=false;
        for(int i=0;i<K;i++){
            win[j]|=A[i]<=j&&!win[j-A[i]];
        }
    }
    if(win[X]) puts("Alice");
    else puts("Bob");
}

int main() {
    while(scanf("%d%d",&X,&K)!=EOF){
        for(int i=0;i<K;i++)scanf("%d",&A[i]);
        solve();
    }
    return 0;
}
