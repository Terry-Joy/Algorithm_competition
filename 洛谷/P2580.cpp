#include<iostream>
#include<cstdio>
#include<cstring>
char s[60];
struct Node{int son[30];int v;}tr[40*10000];
int tot=1,now;
using namespace std;
void stree(char*s)
{
	int len=strlen(s);
	int now=1;
	for(int i=0;i<len;++i)
	{
		if(tr[now].son[s[i]-'a']==0) tr[now].son[s[i]-'a']=++tot;
		now=tr[now].son[s[i]-'a'];
	}
	tr[now].v=1;
}
void find(char*s)
{
	int now=1,n=strlen(s);
	for(int i=0;i<n;++i)
	{
		if(tr[now].son[s[i]-'a']==0){printf("WRONG\n");return;}
			now=tr[now].son[s[i]-'a'];
	}
	if(tr[now].v==-1)printf("REPEAT\n");
    else
	if(tr[now].v==1){printf("OK\n");tr[now].v=-1;}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		stree(s);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",s);
		find(s);
	}
	return 0;
} 
