#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N,M,G,score[50],ans=0;
struct st
{
	char name[100];
	int m;
	int hao[60];
	int sc=0;
}student[1070];
bool cmp1(st x,st y)
{
	if(x.sc!=y.sc)return x.sc>y.sc;
	else return strcmp(x.name,y.name)>0?0:1;
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&G)!=EOF&&N)
	{
		for(int i=1;i<=M;++i)
			scanf("%d",&score[i]);
		for(int i=1;i<=N;++i)
		{
			scanf("%s%d",student[i].name,&student[i].m);
			for(int j=1;j<=student[i].m;++j)
			{
				scanf("%d",&student[i].hao[j]);
				student[i].sc+=score[student[i].hao[j]];	
			}
			if(student[i].sc>=G)
				ans++;
		}
		sort(student+1,student+N+1,cmp1);
		printf("%d\n",ans);
	for(int j=1;j<=ans;++j)
		cout<<student[j].name<<" "<<student[j].sc<<"\n";
	}
	return 0;
}

