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
#define MAX_N 105
#define MAX_Q 100005
#define MAX_M 15
#define MAXK 100000
#define MAX_V 5005
#define MAX_E 100005
#define MAX_K 500
#define inf 1000005
using namespace::std;
typedef long long ll;
typedef vector<string> vec;
int N;
int num[MAX_N][MAX_N];
//dp[i][j]:第i个字母达到一致的最少步数
int dp[MAX_N][MAX_N];
vec S;
bool filter(){
    return true;
}
void solve(){
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    if (!filter()) {
        cout<<"Fegla Won"<<endl;
        return;
    }
    
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        cin>>N;
        S.clear();
        S.resize(N);
        for (int j=0; j<N; j++) {
            cin>>S[j];
        }
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
