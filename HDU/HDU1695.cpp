#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
bool v[maxn];
int phi[maxn],cnt=0,prime[maxn],n,m,num,sum,i;
vector<int>p[maxn];
ll ans;

void init()
{
    v[1]=v[0]=1;phi[1]=1;
    for(int i=2;i<=maxn-9;++i)
    {
        if(!v[i])phi[i]=i-1,prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-9;++j)
        {
            v[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                phi[prime[j]*i]=phi[i]*prime[j];
                break; 
            } 
            else phi[prime[j]*i]=phi[prime[j]]*phi[i];
        } 
    } 
    for(int i=2;i<=maxn-9;++i)
    {
    	int N=i;
    	for(int j=2;j*j<=N;++j)
    	{
    		if(N%j==0){
    			p[i].push_back(j);
    			while(N%j==0)
    				N/=j;
			}
		}
		if(N>1)p[i].push_back(N);
	}
}
void dfs(int pos,int lcm,int id,int x)
{
    if(id==0){
    	if((i+1)&1)
    		num+=(m/lcm);
    	else num-=(m/lcm);
    	return;
	}
   	if(pos==p[x].size())return;
   	if(lcm*p[x][pos]<=m)dfs(pos+1,lcm*p[x][pos],id-1,x);
    dfs(pos+1,lcm,id,x);
    return;
}
int getans(int x)
{
    for(i=0;i<=p[x].size();++i)
        dfs(0,1,i+1,x);
    return m-num;
}
int main()
{
    init(); 
    int t,f=0;
    scanf("%d",&t);
    while(t--)
    { 
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0||k>b||k>d){ printf("Case %d: 0\n",++f);continue;}
        ans=1;
        m=b/k;n=d/k;
        if(m>n)swap(n,m); 
        for(int i=2;i<=m;++i)
            ans+=1ll*phi[i];
        for(int i=m+1;i<=n;++i)
        { 
            num=sum=0;
            ans+=getans(i);
        }
        printf("Case %d: %lld\n",++f,ans);
    }
    return 0; 
}
