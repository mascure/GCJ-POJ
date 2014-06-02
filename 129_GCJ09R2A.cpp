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
#include <map>
#define MAX_N 1005
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;
typedef long long ll;

int n;
int mat[MAX_N][MAX_N];
void solve(){
    //最后一个1出现的位置
    int pos[MAX_N],i,j;
    for (i=0; i<n; i++) {
        pos[i]=0;
        for (j=n; j>=0; j--) {
            if (mat[i][j]==1) {
                pos[i]=j+1;
                break;
            }
        }
    }
    int ans=0;
    for (i=0; i<n-1; i++) {
        int last=i+1;
        j=i;
        while (pos[j]>last) {
            j++;
        }
        while (j>i) {
            swap(pos[j], pos[j-1]);
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d",&mat[i][j]);
            }
        }
        solve();
    }
    return 0;
}

