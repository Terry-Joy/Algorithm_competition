#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
struct data { int x,No; string y; } cow[maxn];
int len,n,m;
string S;
int change(string A)
{
	int len=A.size(),num=0;
	for (int i=0;i<len;i++) num=num*10+A[i]-48;
	return num;
}
bool cmp(data A,data B) { return A.x<B.x || A.x==B.x && A.No<B.No; }
int main()
{
	scanf("%d%d",&len,&n);
	getchar();
	for (int i=1,last,now;i<=n;i++)
	{
		getline(cin,S);
		now=S.find(',');
		string name=S.substr(0,now);
		last=now;
		now=S.find(',',last+1);
		int p=change(S.substr(last+1,now-last-1));
		last=now;
		now=S.find(',',last+1);
		int c=change(S.substr(last+1,now-last-1));
		last=now;
		now=S.find(',',last+1);
		int t=change(S.substr(last+1,now-last-1));
		int r=change(S.substr(now+1,S.size()));
		//cerr<<">>>>>>"<<name<<" "<<p<<" "<<c<<" "<<t<<" "<<r<<endl;
		
		if ((double)((double)10080/(double)(t+r))*(double)(c*ti)>=(double)l)
		{
			m++;
			cow[m].x=p;
			cow[m].y=name;
			cow[m].No=i;
		}
	}
	if (!m)
	{
		puts("no such mower");
		return 0;
	}
	sort(cow+1,cow+1+m,cmp);
	for (int i=1;i<=m;i++)
		if (cow[i].x==cow[1].x) cout<<cow[i].y<<endl; else break;
	return 0;
}