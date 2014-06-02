//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//
/*
 10 10 5
 2 1 6 4 4
 3 1 10 8 8
 4 4 4 1 10
 5 9 9 1 5
 6 10 10 6 10
 */

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stdio.h>
#include <sstream>
#define MAX_N 505
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;
//区域的个数，坐标离散化
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int w,h,n;
int x1[MAX_N],x2[MAX_N];
int y1[MAX_N],y2[MAX_N];

bool fld[MAX_N*6][MAX_N*6];
int compress(int *x1,int *x2,int w){
    vector<int> xs;
    for (int i=0; i<n; i++) {
        for (int d=-1; d<=1; d++) {
            int t1=x1[i]+d,t2=x2[i]+d;
            if (t1>=1&&t1<=w) {
                xs.push_back(t1);
            }
            if (t2>=1&&t2<=w) {
                xs.push_back(t2);
            }
        }
    }
    sort(xs.begin(), xs.end());
    //去重
    xs.erase(unique(xs.begin(), xs.end()),xs.end());
    for (int i=0; i<n; i++) {
        x1[i]=(int)(find(xs.begin(), xs.end(), x1[i])-xs.begin());
        x2[i]=(int)(find(xs.begin(), xs.end(), x2[i])-xs.begin());
    }
    return (int)xs.size();
}

void solve(){
    w=compress(x1,x2,w);
    h=compress(y1,y2,h);
    memset(fld, 0, sizeof(fld));
    //填充有直线的部分
    for (int i=0; i<n; i++) {
        for (int y=y1[i]; y<=y2[i]; y++) {
            for (int x=x1[i]; x<=x2[i]; x++) {
                fld[y][x]=true;
            }
        }
    }
    //求区域的个数
    int ans=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (fld[i][j]) {continue;
            }
            ans++;
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                pair<int, int> top=q.front();q.pop();
                fld[top.first][top.second]=true;
                for (int d=0; d<4; d++) {
                    int xx=top.second+dx[d],yy=top.first+dy[d];
                    if (xx>=0&&xx<w&&yy>=0&&yy<h&&!fld[yy][xx]) {
                        q.push(make_pair(yy, xx));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while(cin>>w>>h>>n){
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i]);
        }
        solve();
    }
    return 0;
}

