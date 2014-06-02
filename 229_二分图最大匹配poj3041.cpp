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
#define MAX_N 1005
#define MAX_Q 100005
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define MAX_K 10005
#define inf 1000005
using namespace::std;
typedef long long ll;
int V;          //定点数
vector<int> G[MAX_V];   //图的邻接表表示
int match[MAX_V];       //所匹配的点
bool used[MAX_V];       //dfs中用到的访问标记

//向图中增加一条连接u和v的边
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
//通过dfs寻找增广路
bool dfs(int v){
    used[v]=true;
    for (int i=0; i<G[v].size(); i++) {
        int u=G[v][i],w=match[u];
        if (w<0||(!used[w]&&dfs(w))) {
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}
//求解二分图的最大匹配
int bipartite_match(){
    int res=0;
    memset(match, -1, sizeof(match));
    for (int v=0; v<V; v++) {
        if (match[v]<0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}
int N,K;
int R[MAX_K],C[MAX_K];

void solve(){
    V=N*2;
    for (int i=0; i<K; i++) {
        add_edge(R[i]-1, N+C[i]-1);
    }
    cout<<bipartite_match()<<endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin>>N>>K) {
        for (int i=0; i<K; i++) {
            //cin>>R[i]>>C[i];
            scanf("%d%d",&R[i],&C[i]);
        }
        solve();
    }
    return 0;
}
