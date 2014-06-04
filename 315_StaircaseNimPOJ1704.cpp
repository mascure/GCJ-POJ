#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_M 20;
#define MAX_K 105
#define MAX_X 10005
typedef long long ll;
using namespace std;
const int MAX_N=1005;
int N,P[MAX_N];
void solve(){
    if(N%2==1)P[N++]=0;
    sort(P,P+N);
    int x=0;
    for(int i=0;i+1<N;i+=2){
        x^=(P[i+1]-P[i]-1);
    }
    if(x==0)puts("Bob will win");
    else puts("Georgia will win");
}

int main() {
    int caseN;
    scanf("%d",&caseN);
    while(caseN--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&P[i]);
        solve();
    }
    return 0;
}
