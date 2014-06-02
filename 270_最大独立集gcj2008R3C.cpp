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
#define MAX_N 105
#define MAX_Q 100005
#define MAX_M 105
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
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
const int dx[4]={-1,-1,1,1},dy[4]={-1,0,-1,0};

int N,M;
char seat[MAX_M][MAX_N+1];  //座位

void sovle(){
    int num=0;
    V=N*M;
    for (int v=0; v<V; v++) {
        G[v].clear();
    }
    for (int y=0; y<M; y++) {
        for (int x=0; x<N; x++) {
            if (seat[y][x]=='.') {
                num++;
                for (int k=0; k<4; k++) {
                    int x2=x+dx[k],y2=y+dy[k];
                    if (0<=x2&&x2<N&&0<=y2&&y2<M&&seat[y2][x2]=='.') {
                        add_edge(x*M+y, x2*M+y2);
                    }
                }
            }
        }
    }
    cout<<num-bipartite_match()<<endl;
}
int main()
{
	freopen("/Users/mascure/Desktop/C-large-practice.in", "r", stdin);
	freopen("/Users/mascure/Desktop/C-large-practice.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        scanf("%d%d",&M,&N);
        getchar();
        for (int j=0; j<M; j++) {
            scanf("%s",seat[j]);
        }
        cout<<"Case #"<<i<<": ";
        sovle();
    }
    return 0;
}
