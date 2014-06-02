#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
//#define MAX_N 105
#define MAX_Q 100005
#define MAX_M 105
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
//#define MAX_K 25
#define MAX_X 15
#define MAX_Y 15
#define inf 100000005
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
const int MAX_N = 100;
const int MAX_K = 25;

int N,K,P[MAX_N][MAX_K];

void sovle(){
    V=N*2;
    for (int v=0; v<V; v++) {
        G[v].clear();
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j) {
                continue;
            }
            bool f=true;
            for (int k=0; k<K; k++) {
                if (P[j][k]>=P[i][k]) {
                    f=false;
                }
            }
            if (f) {
                add_edge(i, N+j);
            }
        }
    }
    cout<<N-bipartite_match()<<endl;
}
int main()
{
	freopen("/Users/mascure/Desktop/C-large-practice.in", "r", stdin);
	freopen("/Users/mascure/Desktop/C-large-practice.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        scanf("%d%d",&N,&K);
        for (int j=0; j<N; j++) {
            for (int k=0; k<K; k++) {
                scanf("%d",&P[j][k]);
            }
        }
        cout<<"Case #"<<i<<": ";
        sovle();
    }
    return 0;
}
