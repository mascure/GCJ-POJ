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

vector<int> A;

ll merge_count(vector<int>& a){
	int n=a.size();
	if(n<=1)return 0;

	ll cnt=0;
	vector<int> b(a.begin(),a.begin()+n/2);
	vector<int> c(a.begin()+n/2,a.end());
	
	cnt+=merge_count(b);
	cnt+=merge_count(c);

	int ai=0,bi=0,ci=0;
	while(ai<n){
		if(bi<b.size()&&(ci==c.size()||b[bi]<=c[ci])){
			a[ai++]=b[bi++];
		}
		else{
			a[ai++]=c[ci++];
			cnt+=n/2-bi;
		}
	}
	return cnt;
}

void solve(){
	cout<<merge_count(A)<<endl;
}

int main()
{
	return 0;
}

