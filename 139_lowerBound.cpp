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
#define MAX_Q 100
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define inf 10000000
using namespace::std;
typedef long long ll;

//满足a[i]>=key的最小的i
int lowerBound(int* a,int n,int key){
    //最后lb+1=ub，可能key大于最大值，则解为(n,n+1]
    int lb=-1,ub=n;
    while (ub-lb>1) {
        int mid=(lb+ub)/2;
        //如果mid满足条件，则解的范围变为(lb,mid]
        if (a[mid]>=key) {
            ub=mid;
        }
        //如果mid不满足条件，则解得范围变为(mid,ub]
        else
            lb=mid;
    }
    return ub;
}

int main()
{
    //freopen("/Users/mascure/Desktop/abc.in", "r", stdin);
    int a[MAX_N],n,key;
    while (cin>>n>>key) {
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        cout<<lowerBound(a, n, key)<<endl;
    }
    return 0;
}

