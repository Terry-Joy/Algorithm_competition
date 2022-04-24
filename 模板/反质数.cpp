#include<cstdio>
#define ll long long
using namespace std;
int n,ans=1,num=1;
int p[15]={1,2,3,5,7,11,13,17,19,23,29,31};
void dfs(int k,ll now,int cnt,int last)	//cnt是约数的个数 now是总数 last剩余指数个数 
{
    if(k==11)			//k当前第几个 
    {
        if(now>ans&&cnt>num){ans=now;num=cnt;}
        if(now<=ans&&cnt>=num){ans=now;num=cnt;}
        return;
    }
    int s=1;
    for(int i=0;i<=last;++i)
    {
        dfs(k+1,now*s,cnt*(i+1),i);
        s*=p[k];
        if(now*s>n)break;
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1,1,1,30);
    printf("%d",ans);
    return 0;
}
