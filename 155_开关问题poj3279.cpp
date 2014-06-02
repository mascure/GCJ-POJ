//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stdio.h>
#include <cmath>
#include <sstream>
#define MAX_N 20
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 1000005
using namespace::std;
typedef long long ll;

const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};

int M,N;
int tile[MAX_N][MAX_N];
int opt[MAX_N][MAX_N];//保存最优解
int flip[MAX_N][MAX_N];//保存中间结果

int get(int x,int y){
    int c=tile[x][y];
    for (int i=0; i<5; i++) {
        int xx=x+dx[i],yy=y+dy[i];
        if (xx>=0&&xx<M&&yy>=0&&yy<N) {
            c+=flip[xx][yy];
        }
    }
    return c%2;
}

int calc(){
    //求出从第二行开始的翻转方法
    for (int i=1; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (get(i-1,j)!=0) {
                flip[i][j]=1;
            }
        }
    }
    //判断最后一行是否全白
    for (int i=0; i<M; i++) {
        if (get(M-1,i)!=0) {
            return -1;
        }
    }
    //统计翻转的次数
    int res=0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (flip[i][j]) {
                res+=flip[i][j];
            }
        }
    }
    return res;
}

void solve(){
    int res=-1;
    //按照字典序枚举第一行的所有可能性
    for (int i=0; i< 1<<N; i++) {
        memset(flip, 0, sizeof(flip));
        for (int j=0; j<N; j++) {
            flip[0][N-j-1]= (i>>j)&1;
        }
        int num=calc();
        if (num>=0&&(res<0||res>num)) {
            res=num;
            memcpy(opt, flip, sizeof(flip));
        }
    }
    if (res<0) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                printf("%d%c",opt[i][j],j+1==N?'\n':' ');
            }
        }
    }
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while(cin>>M>>N){
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d",&tile[i][j]);
            }
        }
        solve();
    }
    return 0;
}

