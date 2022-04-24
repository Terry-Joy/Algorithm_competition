#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn =1e4+10;
int vis[maxn],L,M;
int main()
{
	cin>>L>>M;
    int l,r,ans=0;
	memset(vis,0,sizeof(vis));
    for(int i=0;i<M;++i)
    {
		scanf("%d%d",&l,&r);
        for(int j=l;j<=r;++j){
            if(!vis[j])
                vis[j]=1;
        }
    }
    for(int i=0;i<=L;++i) {
        if(!vis[i])
            ans++;
    }
	cout<<ans<<"\n";
    return 0;
}