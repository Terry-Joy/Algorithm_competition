#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1010];
bool vis[1010];
int gcd(int a,int b){ return b?gcd(b,a%b):a;}
int main(){ 
    int t,n;
    cin>>t;
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]),vis[i]=0;
        sort(a+1,a+1+n);
        vector<int>ans;
        int now=a[n],id=0,k=0;
        int cnt=0;
        ans.push_back(now);
        while(cnt<n-1){ 
            k=0,id=0;
            for(int i=1;i<=n-1;++i)
                if(!vis[i]&&gcd(a[i],now)>k)k=gcd(a[i],now),id=i;
            now=gcd(now,a[id]);
            cnt++;
            vis[id]=1;
            ans.push_back(a[id]);
        }
        for(auto&v:ans)
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;
}
