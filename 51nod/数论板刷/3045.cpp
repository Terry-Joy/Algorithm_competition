#include<bits/stdc++.h>

using namespace std;
int t,m,n;
vector<int>G[10005];
int gcd(int a,int b){ 
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d",&t);
    for(int i=1;i<=10000;++i){ 
        for(int j=1;j<=10000/i;++j){ 
            G[i*j].push_back(i);
        }
    }
    while(t--){ 
        int ans=1e9;
        scanf("%d%d",&m,&n);
        if(m==n){ 
            printf("%d\n",2*n);
        }else{ 
            ans=1e9;
            int mp=m/n;
            for(auto v:G[mp]){ 
                if(v*v>=mp)break;
                int k=mp/v;
                if(gcd(k,v)==1)
                ans=min(v*n+k*n,ans);
            }
        }
        printf("%d\n",ans);
    } 
    return 0;
}
