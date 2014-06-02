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
typedef vector<int> vec;
typedef vector<vec> mat;
const int M=1000;
mat mul(mat& A, mat& B){
    mat C(A.size(),vec(B[0].size()));
    for (int i=0; i<A.size(); i++) {
        for (int k=0; k<B.size(); k++) {
            for (int j=0; j<B[0].size(); j++) {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}
//计算A^n
mat pow(mat A,ll n){
    mat B(A.size(),vec(A[0].size()));
    for (int i=0; i<A.size(); i++) {
        B[i][i]=1;
    }
    while (n>0) {
        if (n&1) {
            B=mul(B, A);
        }
        A=mul(A, A);
        n>>=1;
    }
    return B;
}
int n;
void sovle(){
    mat A(2,vec(2,0));
    A[0][0]=3;A[0][1]=5;
    A[1][0]=1;A[1][1]=3;
    A=pow(A, n);
    printf("%03d\n",(A[0][0]*2+M-1)%M);
}
int main()
{
	freopen("/Users/mascure/Desktop/C-large-practice.in", "r", stdin);
	freopen("/Users/mascure/Desktop/C-large-practice.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        scanf("%d",&n);
        cout<<"Case #"<<i<<": ";
        sovle();
    }
    return 0;
}
