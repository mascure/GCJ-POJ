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
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
#define MAX_X 15
#define MAX_Y 15
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
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
//输入
int X,Y;
char field[MAX_X][MAX_Y+1];

vector<int> dX,dY;      //门的坐标
vector<int> pX,pY;      //人得坐标
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];   //最近距离
bool  C(int t){
    int d=dX.size(),p=pX.size();
    
    //0~d-1:时间1对应的门
    //d~2*d-1:时间2对应的门
    //(t-1)d~td-1:时间t对应的门
    //td~td+p:人
    V=t*d+p;
    for (int v=0; v<V; v++) {
        G[v].clear();
    }
    //建边
    for (int i=0; i<d; i++) {
        for (int j=0; j<p; j++) {
            for (int k=dist[dX[i]][dY[i]][pX[j]][pY[j]]; k>=0&&k<=t; k++) {
                //时间k对应的门
                add_edge((k-1)*d+i, t*d+j);
            }
        }
    }
    return bipartite_match()==p;
}
//通过BFS计算最短距离
void bfs(int x,int y,int d[MAX_X][MAX_Y]){
    queue<int> qx,qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);
    while (!qx.empty()) {
        x=qx.front();qx.pop();
        y=qy.front();qy.pop();
        for (int k=0; k<4; k++) {
            int x2=x+dx[k],y2=y+dy[k];
            if (x2>=0&&x2<X&&y2>=0&&y2<Y&&field[x2][y2]=='.'&&d[x2][y2]<0) {
                d[x2][y2]=d[x][y]+1;
                qx.push(x2);
                qy.push(y2);
            }
        }
    }
}
void solve(){
    int n=X*Y;
    dX.clear();dY.clear();
    pX.clear();pY.clear();
    memset(dist, -1, sizeof(dist));
    
    //计算到各个门的最近距离
    for (int x=0; x<X; x++) {
        for (int y=0; y<Y; y++) {
            if (field[x][y]=='D') {
                dX.push_back(x);
                dY.push_back(y);
                bfs(x,y,dist[x][y]);
            }
            else if(field[x][y]=='.'){
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }
    
    //利用二分搜索求解所有人安全逃脱所需的最短时间
    int lb=-1,ub=n+1;
    while (ub-lb>1) {
        int mid=(lb+ub)/2;
        if (C(mid)) {
            ub=mid;
        }
        else
            lb=mid;
    }
    if (ub>n) {
        cout<<"impossible"<<endl;
    }
    else
        cout<<ub<<endl;
}
void solve2(){
    int n=X*Y;
    dX.clear();dY.clear();
    pX.clear();pY.clear();
    memset(dist, -1, sizeof(dist));
    
    //计算到各个门的最近距离
    for (int x=0; x<X; x++) {
        for (int y=0; y<Y; y++) {
            if (field[x][y]=='D') {
                dX.push_back(x);
                dY.push_back(y);
                bfs(x,y,dist[x][y]);
            }
            else if(field[x][y]=='.'){
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }
    
    int d=dX.size(),p=pX.size();
    for (int v=0; v<n*d+p; v++) {
        G[v].clear();
    }
    //0~d-1:时间1对应的门
    //d~2*d-1:时间2对应的门
    //(t-1)d~td-1:时间t对应的门
    //td~td+p:人
    //建边
    for (int i=0; i<d; i++) {
        for (int j=0; j<p; j++) {
            for (int k=dist[dX[i]][dY[i]][pX[j]][pY[j]]; k>=0&&k<=n; k++) {
                //时间k对应的门
                add_edge((k-1)*d+i, n*d+j);
            }
        }
    }
    
    //求所有人安全通过所需的最少时间
    if (p==0) {
        cout<<0<<endl;
        return;
    }
    int num=0;
    memset(match, -1, sizeof(match));
    for (int v=0; v<n*d; v++) {
        memset(used, 0, sizeof(used));
        if (dfs(v)) {
            if (++num==p) {
                cout<<v/d+1<<endl;
                return;
            }
        }
    }
    cout<<"impossible"<<endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int caseN;
    cin>>caseN;
    while (caseN--) {
        cin>>X>>Y;
        getchar();
        for (int i=0; i<X; i++) {
            scanf("%s",field[i]);
        }
        solve2();
    }
    return 0;
}
