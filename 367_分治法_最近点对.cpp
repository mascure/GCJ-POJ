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
typedef pair<double,double> P;	//first����x���꣬second����y����
//����
int N;
P A[MAX_N];
//����y��������ıȽϺ���
bool compare_y(P a,P b){
	return a.second<b.second;
}
//�����a����x�ź���
double closest_pair(P *a,int n){
	if(n<=1)return inf;
	int m=n/2;
	double x=a[m].first;
	double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);	//�鲢�����ź��������

	vector<P> b;	//����ֱ�ߵľ���С��d�Ķ������
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

