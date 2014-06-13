#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_N 100005
#define MAX_M 50005
typedef long long ll;
using namespace std;
const int MAX_MATCH=65;
const int MAX_SQUARE=60;
//火柴棒数(2N(N+1))和正方形数(N(N+1)(2N+1)/6)
int M,S;
//m[i][j]=true表示火柴棒i属于正方形j
bool m[MAX_MATCH][MAX_SQUARE];
//mmax[i]表示正方形j中火柴棒的最大编号
int mmax[MAX_SQUARE];

//考虑p以后的火柴时解的下界
int hstar(int p,vector<bool> state){
	vector<pair<int,int> > ps;
	for(int i=0;i<S;i++){
		if(state[i]){
			//统计剩余正方形包含的火柴棒数
			int num=0;
			for(int j=p;j<M;j++){
				if(m[j][i])num++;
			}
			ps.push_back(make_pair(num,i));
		}
	}
	//按火柴棒数从小到大排序
	sort(ps.begin(),ps.end());
	int res=0;
	//used[i]=true 表示当前集合中已经有包含火柴棒i的正方形了
	vector<bool> used(M,false);
	for(int i=0;i<ps.size();i++){
		int id=ps[i].second;
		bool ok=true;
		//判断是否将正方形id加入x中
		for(int j=p;j<M;j++){
			if(used[j]&&m[j][id])ok=false;
		}
		if(ok){
			res++;
			for(int j=p;j<M;j++){
				if(m[j][id])used[j]=true;
			}
		}
	}
	return res;
}

//p是当前考察的火柴棒编号，num是至今已经移除的火柴棒的根数
//state[i]=true表示正方形i尚未被破坏
//已经找到的最优解
int min_res;
int dfs(int p,int num,vector<bool> state){
	//如果检查完了所有火柴棒，也就破坏了所有的正方形
	if(p==M)return min_res=num;
	
	//如果比已知的最优解要差，则不继续搜索
	if(num+hstar(p,state)>=min_res) return inf;

	//如果一定要移除火柴棒p，则use=true
	//如果一定不移除火柴棒p（移除不会破坏任何正方形），则notuse=true
	bool use=false,notuse=true;
	for(int i=0;i<S;i++){
		//火柴p会破坏正方形i，则可以移除
		if(state[i]&&m[p][i])notuse=false;
		//只剩火柴棒p可以破坏正方形i了，则必须移除
		if(state[i]&&mmax[i]==p)use=true;
	}

	int res=inf;
	//不移除p
	if(!use)res=min(res,dfs(p+1,num,state));
	for(int i=0;i<S;i++){
		if(m[p][i])state[i]=false;
	}
	//移除火柴棒
	if(!notuse)res=min(res,dfs(p+1,num+1,state));
	return res;
}

void solve(){
	vector<bool> state(S,true);
	cout<<dfs(0,0,state)<<endl;
}

int main()
{
	return 0;
}

