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
#define MAX_K 500
#define inf 1000005
using namespace::std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;//存储线段树的全局数组
/*
 二分图最大匹配 匈牙利算法
 */
int ma[MAX_N][MAX_N];
int link[MAX_N],used[MAX_N];
int n,m;
bool can(int t){
    for (int i=0; i<m; i++) {
        if (used[i]==0&&ma[t][i]) {
            used[i]=1;
            if (link[i]==-1||can(link[i])) {
                link[i]=t;
                return true;
            }
        }
    }
    return false;
}
int maxMatch(){
    int res=0;
    for (int i=0; i<n; i++) {
        memset(used, 0, sizeof(used));
        if (can(i)) {
            res++;
        }
    }
    return res;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
    return 0;
}
