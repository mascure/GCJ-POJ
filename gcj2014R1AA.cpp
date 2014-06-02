/*
 2014gcjR1AA的第一名代码
 思路：由于两组串如果能匹配，一定是一一对应。对于第一组中得第一个串来说，经过某个最小次数的翻转，一定可以到达第二组中得某个串；因此，通过分别计算第一组第一个串到第二组所有串的次数，取最小值，即所求。排序之后，可以使判断两组串是否相等加快。
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 999999999
using namespace std;
char p[201][50];
bool o[201];
struct A{
	char p[50];
	bool operator <(const A &q)const{
		return strcmp(p, q.p) < 0;
	}
}q[201],r[201];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, TC, T, j, n, m, k, l, R, S;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d%d", &n, &m);
		for (j = 0; j < n; j++){
			scanf("%s", p[j]);
		}
		for (j = 0; j < n; j++){
			scanf("%s", q[j].p);
		}
        //目标组排序
		sort(q, q + n);
		R = INF;
		for (j = 0; j < n; j++){
			S = 0;
            //计算第一组中得第一个串到第j个串的翻转次数
			for (k = 0; k < m; k++){
				if (p[0][k] != q[j].p[k])o[k] = 1, S++;
				else o[k] = 0;
			}
            //已经大于当前的最优解
			if (S >= R)continue;
			for (k = 0; k < n; k++){
				for (l = 0; l < m; l++){
					r[k].p[l] = p[k][l];
					if (o[l])r[k].p[l] = '0' + '1' - r[k].p[l];
				}
				r[k].p[m] = 0;
			}
            //计算翻转完后是否所有串到达目标
			sort(r, r + n);
			for (k = 0; k < n; k++){
				if (strcmp(r[k].p, q[k].p) != 0)break;
			}
            //如果是得话，更新最优解
			if (k == n)R = S;
		}
		if (R != INF)printf("%d\n", R);
		else printf("NOT POSSIBLE\n");
	}
}
