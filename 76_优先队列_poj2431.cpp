//
//  main.cpp
//  abc
//
//  Created by mascure on 14-3-22.
//  Copyright (c) 2014年 mascure. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAXN 100
#define MAXM 100
#define MAXK 100000
#define inf 10000000
using namespace::std;

int n,L,P;
int A[MAXN],B[MAXN];

int main(int argc, const char * argv[])
{
    freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int i;
    while(cin>>n>>L>>P){
        for (i=0; i<n; i++) {
            cin>>A[i];
        }
        for (i=0; i<n; i++) {
            cin>>B[i];
        }
        int contain=P,last_pos=0;
        priority_queue<int> q;
        int ans=0;
        for (i=0; i<n; i++) {
            int dis=A[i]-last_pos;
            while (contain-dis<0) {
                if (q.empty()) {
                    cout<<"-1"<<endl;
                    return 0;
                }
                contain+=q.top();
                q.pop();
                ans++;
            }
            contain-=dis;
            last_pos=A[i];
            q.push(B[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

