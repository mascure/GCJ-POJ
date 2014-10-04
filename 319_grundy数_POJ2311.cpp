#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
//#include <unordered_set>
using namespace std;
const int MAX_N=1000005;
const int inf=1000000;
const int MOD=1000000007;
const int MAX_WH=200;
typedef long long ll;

int mem[MAX_WH+1][MAX_WH+1];
int grundy(int w,int h){
	if(mem[w][h]>=0)return mem[w][h];
	set<int> s;
	for(int i=2;w-i>=2;i++)s.insert(grundy(i,h)^grundy(w-i,h));
	for(int i=2;h-i>=2;i++)s.insert(grundy(w,i)^grundy(w,h-i));
	int g=0;
	while(s.count(g))g++;
	return mem[w][h]=g;
}
void solve(int w,int h){
	if(grundy(w,h)!=0)puts("WIN");
	else puts("LOSE");
}

int main(){
	int w,h;
	memset(mem,-1,sizeof(mem));
	while(cin>>w>>h){
		solve(w,h);
	}
	return 0;
}