#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[610],road[1010],n,p1,p2,d,a[610][2],r[610],ans[605],dp[606][305];
int find(int x)
{
   	if(fa[x]==x)return x;
   	else
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        road[x]^=road[t];         //路径压缩时更改路径值
         return fa[x];
    } 
   
}
void init()
{
    for(int i=1;i<=p1+p2;++i)
        fa[i]=i,road[i]=0,a[i][0]=a[i][1]=0; 
}
int main()
{
    while(scanf("%d%d%d",&n,&p1,&p2)!=EOF)
    {
        if(!n&&!p1&&!p2)
            break;
        init();
        while(n--)
        {
            char ch[5];
            int a,b;
            scanf("%d%d%s",&a,&b,ch);
            if(ch[0]=='y')
                d=0;
            else d=1;
            int fx=find(a);
            int fy=find(b);       //若fx==fy则关系在路径压缩时已经更新
            if(fx!=fy)
            {
                fa[fy]=fx;
                road[fy]=road[a]^d^road[b]; //合并时向量推出异或关系
            }
        }
        int tot=0;
        for(int i=1;i<=p1+p2;++i)
        {
            if(i==find(i))  		//road[i]��ʾ����ڵ�Ĺ�ϵ 
            {//�����ҵ��� 
                r[++tot]=i;			//r�����洢ÿ�����ϵĴ��� 
                for(int j=1;j<=p1+p2;++j)
                {
                    if(find(j)==i)
                    	if(road[j]==0)
                    	a[tot][0]++;
                    	else a[tot][1]++;
                } 
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=tot;++i)
        {
            for(int j=p1;j>=a[i][0];--j)
                dp[i][j]+=dp[i-1][j-a[i][0]];
            for(int j=p1;j>=a[i][1];--j)
                dp[i][j]+=dp[i-1][j-a[i][1]]; 
        }
        if(dp[tot][p1]!=1)
        {
            puts("no");
            continue;
        }
        int p=p1,num=0;
        for(int i=tot;i>=1;--i)
        {
           if(dp[i-1][p-a[i][0]]==1)        //第i个集合选择和祖先一样为天使
           {
                for(int j=1;j<=p1+p2;++j)
                {
                   if(find(j)==r[i]&&road[j]==0)
                       ans[num++]=j;
                }
                p-=a[i][0];                         //相等于逆序推导
           } 
           else{ 
                for(int j=1;j<=p1+p2;++j)
            
                   if(find(j)==r[i]&&road[j]==1)
                      ans[num++]=j;
                   p-=a[i][1]; 
           }
        }    
        sort(ans,ans+num);
           for(int i=0;i<num;++i)
               printf("%d\n",ans[i]);
           puts("end");
    }
    return 0;
}
