#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_M 20;
#define MAX_K 105
#define MAX_X 10005
typedef long long ll;
using namespace std;
const int MAX_N=1005;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int dot(const Point& a,const Point& b){
        return a.x*b.x+a.y*b.y;
    }
    int det(const Point& a,const Point& b){
        return a.x*b.y-a.y*b.x;
    }
    int maxPoints(vector<Point> &points) {
        int res=1;
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int now=2;
                for(int k=0;k<points.size();k++){
                    if(k!=i&&k!=j){
                            //i,k  j,k
                        if(det(Point(points[i].x-points[k].x,points[i].y-points[k].y),Point(points[j].x-points[k].x,points[j].y-points[k].y))==0)now++;
                    }
                }
            }
            if(now>res)res=now;
        }
        return res;
    }
};

int main() {
    int caseN;
    scanf("%d",&caseN);
    while(caseN--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&P[i]);
        solve();
    }
    return 0;
}
