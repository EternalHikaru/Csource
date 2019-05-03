#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<queue>
void BFS();
using namespace std;


int n;
double a[1001][1001] = { 0 };
struct Node
{
	int x;
	int y;
	double time;
}start;

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };//上下左右

//广度优先搜索
int main()
{
	while (1)
	{
		memset(a, 0, sizeof(a));
		double t1, t2, t3, t4;
		scanf("%d", &n);
		if (n == 0) break;
		scanf("%lf%lf%lf%lf", &t1, &t2, &t3, &t4);
		for (int p = 0; p < n; ++p)
		{
			for (int q = 0; q < n; ++q)
			{
				scanf("%lf", &a[p][q]);
				if (a[p][q] - 1<0.00001&&a[p][q]-1>-0.00001 ) a[p][q] = t1;
				if (a[p][q] - 2<0.00001&&a[p][q]-2>-0.00001 ) a[p][q] = t2;
				if (a[p][q] - 3<0.00001&&a[p][q]-3>-0.00001 ) a[p][q] = t3;
				if (a[p][q] - 4<0.00001&&a[p][q]-4>-0.00001 ) a[p][q] = t4;
				if (a[p][q] - 5<0.00001&&a[p][q]-5>-0.00001 ) a[p][q] = -3;
			}
		}
		a[n - 1][0] = -1;//出发
		a[0][n - 1] = 0;//终点
		start.x = n - 1;
		start.y = 0;
		start.time = 0;
		BFS();
	}
}

void BFS()
{
	queue<Node>q;
	Node q1, q2;
	q.push(start);
	double mintime = DBL_MAX;
	while (!q.empty())
	{
		int i;
		q1 = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			q2.x = q1.x + dir[i][0];
			q2.y = q1.y + dir[i][1];
			if (q2.x >= 0 && q2.y >= 0 && q2.x < n&&q2.y < n&&a[q2.x][q2.y]+3>0.00001)
			{
				q2.time = q1.time + a[q2.x][q2.y];
				if (q2.x==0&&q2.y==n-1)
				{	
					printf("%lf\n", q2.time);
					return;
				}
				q.push(q2);
			}	
		}
	}
	printf("Impossible!\n");
	return;
}