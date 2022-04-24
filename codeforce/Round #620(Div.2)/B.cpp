#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
char s[110][60];int n,m;
bool v[110];
vector<int>q,b;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			int flag=1;
			for(int k=0;k<m;++k)
				if(s[i][k]!=s[j][m-k-1]){flag=0;break;}
			if(flag)
			{
				v[i]=v[j]=1;
				q.push_back(i),b.push_back(j);	
			}		
		}
	}
	int f=-1;
	for(int i=1;i<=n;++i)
	{
		if(!v[i])
		{
			int flag=1;
			for(int j=0;j<m;++j)
				if(s[i][j]!=s[i][m-j-1]){flag=0;break;}
			if(flag){f=i;break;}
		}
	}
	cout<<q.size()*m*2+(f!=-1)*m<<"\n";
	for(int i=0;i<q.size();++i)
		cout<<s[q[i]];
	if(f!=-1)cout<<s[f];
	for(int i=b.size()-1;i>=0;--i)
		cout<<s[b[i]];
	return 0;
} 
