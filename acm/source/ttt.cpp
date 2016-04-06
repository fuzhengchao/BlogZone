#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

//①按照每个点 x 值由小到大进行排序，若 x 相同，则按照 y 由小到大进行排序，计算相邻两点的最短距离，即为len1。
//②按照每个点 y 值由小到大进行排序，若 y 相同，则按照 x 由小到大进行排序，计算相邻两点的最短距离，即为len2。
//答案即为：min（len1，len2）。

struct Point
{
	double x;
	double y;
}coor[100001];

bool cmp1(const Point a,const Point b)
{
	if(a.x<b.x)
		return true;
	if(a.x>b.x)
		return false;
	else
		return a.y<b.y;
}

bool cmp2(const Point a,const Point b)
{
	if(a.y<b.y)
		return true;
	if(a.y>b.y)
		return false;
	else
		return a.x<b.x;
}

double num(int i,int j)
{
	return sqrt( pow( (coor[i].x-coor[j].x),2 ) + pow( (coor[i].y-coor[j].y),2 ) );  //计算两点之间的距离 	
}

int main()
{
	double radius=0;  //定义半径  
	int i,N;
	while(scanf("%d",&N) && N!=0)  //N大于2小于100000 
	{
		for(i=1 ; i<=N ; i++)
			scanf("%lf %lf",&coor[i].x , &coor[i].y);
		sort(coor+1,coor+N+1,cmp1);  //先排x轴 
		radius=num(1,2);
		for(i=2;i<N;i++)
		{
			if( radius>num(i,i+1) )
				radius=num(i,i+1);	
		}
		sort(coor+1,coor+N+1,cmp2);  //再排y轴 
		for(i=1;i<N;i++)
		{
			if( radius>num(i,i+1) ) 
				radius=num(i,i+1);	
		}
		printf("%.2f\n",radius/2);
	}
	return 0;
}