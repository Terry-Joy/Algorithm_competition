#include<bits/stdc++.h>
using namespace std;
typedef double db;
db r,h,x,y,z,vx,vy,vz;
int main(){
	int t;
	cin>>t;
	int T=0;
	while(t--){
		cin>>r>>h>>x>>y>>z>>vx>>vy>>vz;
		db a=vx*vx+vy*vy-r*r/h/h*vz*vz,b=2*(x*vx+y*vy+r*r*vz/h-r*r*vz*z/h/h),c=x*x+y*y-r*r/h/h*(h-z)*(h-z);
		db ans=(-b-sqrt(b*b-4*a*c))/(2*a);
		printf("Case %d: %.10f\n",++T,ans);
	}	
	return 0;
}