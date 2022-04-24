#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=55;
ll c[maxn][maxn];
int cnt[maxn];
char s[maxn];
ll solve(int x){ 
    ll ans=1;
    for(int i=0;i<10;++i)ans*=c[x][cnt[i]],x-=cnt[i];
    return ans;
}
int main(){ 
    cin>>(s+1);
    int n=strlen(s+1);
    c[0][0]=1;
    for(int i=1;i<=50;++i){ 
        c[i][0]=1;
        for(int j=1;j<=i;++j){ 
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    for(int i=1;i<=n;++i){ 
        cnt[s[i]-'0']++;
    }
    ll ans=0;
    for(int i=1;i<=n;++i){ 
        for(int j=0;j<(s[i]-'0');++j){ 
            if(!cnt[j])continue;
            cnt[j]--;
            ans+=solve(n-i);
            cnt[j]++;
        }   
        cnt[s[i]-'0']--;
    }
    cout<<ans;
    return 0;
}
