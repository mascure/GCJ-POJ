//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
#define MAXN 160005
#define MAXK 100000
#define inf 10000000
using namespace::std;

int p[MAXN],r[MAXN];
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
bool Same(int a,int b){
    return Find(a)==Find(b);
}
int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i,N,k;
    while (scanf("%d%d",&N,&k)!=EOF) {
        n=3*N;
        Init();
        int ans=0;
        for (i=0; i<k; i++) {
            int flag,x,y;
            scanf("%d%d%d",&flag,&x,&y);
            if (x<=0||x>N||y<=0||y>N||(flag==2&&x==y)) {
                ans++;
                continue;
            }
            x--;y--;
            if (flag==1) {
                if (Same(x, y+N)||Same(x, y+2*N)) {
                    ans++;
                }
                else{
                    Merge(x, y);
                    Merge(x+N, y+N);
                    Merge(x+2*N, y+2*N);
                }
            }
            else{
                if (Same(x, y)||Same(x, y+2*N)) {
                    ans++;
                }
                else{
                    Merge(x, y+N);
                    Merge(x+N, y+2*N);
                    Merge(x+2*N, y);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

