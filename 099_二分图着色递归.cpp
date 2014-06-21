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
#include <set>
#define MAXN 1005
#define MAXK 100000
#define inf 10000000
using namespace::std;

int n;
int m[MAXN][MAXN];
int color[MAXN];

bool dfs(int x,int flag){
    if (color[x]==0-flag) {
        return false;
    }
    if (color[x]==flag) {
        return true;
    }
    color[x]=flag;
    int i;
    for (i=0; i<n; i++) {
        //若有边，则设置颜色
        if (m[x][i]==1) {
            if(!dfs(i, 0-flag))return false;
        }
    }
    return true;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i,k;
    while (scanf("%d%d",&n,&k)!=EOF) {
        memset(m, 0, sizeof(m));
        memset(color, 0, sizeof(color));
        for (i=0; i<k; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            m[a][b]=m[b][a]=1;
        }
        for (i=0; i<n; i++) {
            if (color[i]==0) {
                if(!dfs(i,1)){
                    cout<<"No"<<endl;
                    break;
                }
            }
        }
        if (i==n) {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}

