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
#define MAX_N 1005
#define MAX_M 50005
typedef long long ll;
using namespace std;
int V;		//������
vector<int> G[MAX_V];	//ͼ���ڽӱ��ʾ
vector<int> rG[MAX_V];	//�ѱ߷�����ͼ
vector<int> vs;			//	�������˳��Ķ����б�
bool used[MAX_V];		//���ʱ��
int cmp[MAX_V];			//����ǿ��ͨ��������������
void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}
void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v,int k){
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}
int scc(){
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++){
		if(!used[v]) dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int v=vs.size()-1;v>=0;v--){
		if(!used[vs[v]]) rdfs(vs[v],k++);
	}
	return k;
}
//2-SAT ����
int N;
int S[MAX_N],T[MAX_N],D[MAX_N];	//s��t�ǻ���ɷ��Ӻ��ʱ��
//xiΪ��ȼ����ڿ�ʼʱ����
void solve(){
	//���ߣ�0~N-1����a,b,c��..
	//N~2*N-1����-a,-b,-c
	V=2*N;
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			//��ʼ�Ϳ�ʼ��-xi��-xj,xi��-xj,xj��-xi
			if(min(S[i]+D[i],S[j]+D[j])>max(S[i],S[j])){
				add_edge(i,N+j);
				add_edge(j,N+i);
			}
			//��ʼ�ͽ�����-xi��xj,xi��xj,-xj��-xi
			if(min(S[i]+D[i],T[j])>max(S[i],T[j]-D[j])){
				add_edge(i,j);
				add_edge(N+j,N+i);
			}
			//�����Ϳ�ʼ��xi��-xj,-xi��-xj,xj��xi
			if(min(T[i],S[j]+D[j])>max(T[i]-D[i],S[j])){
				add_edge(N+i,N+j);
				add_edge(j,i);
			}
			//�����ͽ�����xi��xj,-xi��xj,-xj��xi
			if(min(T[i],T[j])>max(T[i]-D[i],T[j]-D[j])){
				add_edge(N+i,j);
				add_edge(N+j,i);
			}
		}
	}
	scc();
	bool res=true;
	for(int i=0;i<N;i++){
		if(cmp[i]==cmp[N+i])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	//��������㣬�����һ���
	for(int i=0;i<N;i++){
		//xiΪ�棬���ڽ����ʽ��ʼʱ����
		if(cmp[i]>cmp[N+i])
		{
			printf("%02d:%02d %02d:%02d\n",S[i]/60,S[i]%60,(S[i]+D[i])/60,(S[i]+D[i])%60);
		}
		else
		{
			printf("%02d:%02d %02d:%02d\n",(T[i]-D[i])/60,(T[i]-D[i])%60,T[i]/60,T[i]%60);
		}
	}
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++){
			int sh,sm,th,tm;
			scanf("%d:%d %d:%d %d",&sh,&sm,&th,&tm,&D[i]);
			S[i]=sh*60+sm;
			T[i]=th*60+tm;
		}
		solve();
	}
	return 0;
}

