#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
#define maxn 1010
#define INF 0x3f3f3f3f
const double eps=1e-8;
const double PI=acos(-1.0);
int sgn(double x){
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;	
	else return 1;
}
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y) {x=_x;y=_y;}
	Point operator -(const Point &b)const {return Point(x - b.x,y - b.y);}
	double operator ^(const Point &b)const {return x*b.y - y*b.x;}
	double operator*(const Point &b)const {return x*b.x+y*b.y;}
};
struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {s=_s;e=_e;}
};
double dist(Point a,Point b)
{
	return sqrt((a-b)*(a-b));
}
Point list[maxn]; int top;
int Stack[maxn];
bool _cmp(Point p1,Point p2)
{
	double tmp=(p1-list[0])^(p2-list[0]);
	if(sgn(tmp)>0) return true;
	if(sgn(tmp)==0 && sgn(dist(p1,list[0])-dist(p2,list[0]))<=0) return true;
	return false;
}
void Graham(int n)
{
	Point p0;
	int k=0;
	p0=list[0];
	for(int i=1;i<n;i++){
		if((p0.y>list[i].y) || (p0.y==list[i].y && p0.x>list[i].x)){
			p0=list[i]; k=i;
		}
    }
	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);
	if(n==1){
		top=1;
		Stack[0]=0;
		return;
	}
	if(n==2){
		top=2;
		Stack[0]=0;
		Stack[1]=1;
		return;
	}
	Stack[0]=0; Stack[1]=1; top=2;
	for(int i=2;i<n;i++){
		while(top>1 &&sgn((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]]))<=0)
		top--;
		Stack[top++]=i;
	}
}
int n,p,cost[maxn][maxn],dp[maxn][maxn];
int main(){
	while(cin>>n>>p){
		for(int i=0;i<n;i++){
			cin>>list[i].x>>list[i].y;
		}
		Graham(n);
		if(top<n){
			cout<<"I can't cut."<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				cost[i][j]=cost[j][i]=abs(list[i].x+list[j].x)*abs(list[i].y+list[j].y)%p;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=INF;
			}
				dp[i][(i+1)%n]=0;
		}
		for(int len=2;len<n;len++){
			for(int i=0;i<n;i++){
				int j=i+len;
				for(int k=i+1;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cost[i][k]+cost[k][j]);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}
