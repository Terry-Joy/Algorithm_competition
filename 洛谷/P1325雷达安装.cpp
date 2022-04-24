#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x[1010];
int y[1010]; 
struct map2
{
	double left;
	double right;
};
;
map2 sum[1010];
bool cmp1(map2 a,map2 b)
{
	if (a.left==b.left)
		return a.right>b.right;
	return a.left<b.left;
}
int main()
{
	int n,a,f; 
	cin>>n>>a;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
		if(y[i]>a)
		f=1;
	}
	if(f)
		{
		cout<<"-1"<<endl;
		f=0;
		}
	else 
	{
		for(int i=1;i<=n;++i)
		{
			sum[i].left=x[i]-sqrt(a*a*1.0-1.0*y[i]*y[i]);
			sum[i].right=x[i]+sqrt(a*a*1.0-1.0*y[i]*y[i]);
		}
		sort(sum+1,sum+n+1,cmp1);
		int ans=0;
		int temp; 
	    for(int i = 1;i <= n;i++)
		 {
            if(i == 1) temp = sum[i].right, ans++;
        else
		{
            if(temp >= sum[i].left) continue;
            else ans++, temp = sum[i].right;
        }
   	  }
   	  cout<<ans;
	}
	return 0;
}
 
