#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<math.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_N 100005
#define MAX_M 50005
typedef long long ll;
using namespace std;
typedef pair<double,double> P;	//first保存x坐标，second保存y坐标
//输入
int N;
P A[MAX_N];
//用于y坐标排序的比较函数
bool compare_y(P a,P b){
	return a.second<b.second;
}
//传入的a按照x排好序
double closest_pair(P *a,int n){
	if(n<=1)return inf;
	int m=n/2;
	double x=a[m].first;
	double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);	//归并两个排好序的数列

	vector<P> b;	//将到直线的距离小于d的顶点加入
	for(int i=0;i<n;i++){
		if(fabs(a[i].first-x)>=d)continue;
		for(int j=0;j<b.size();j++){
			double dx=a[i].first-b[b.size()-j-1].first;
			double dy=a[i].second-b[b.size()-j-1].second;
			if(dy>=d)break;
			d=min(d,sqrt(dx*dx+dy*dy));
		}
		b.push_back(a[i]);
	}
}
void solve(){
	sort(A,A+N);
	printf("%f\n",closest_pair(A,N));
}

int main()
{
	return 0;
}

