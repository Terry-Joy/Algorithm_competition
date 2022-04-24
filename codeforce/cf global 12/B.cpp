#include<bits/stdc++.h>
#define  fi first
#define  se second
using namespace std;
typedef long long ll;
int t,n,k;
const int maxn=105;
pair<int,int>P[maxn];
int main(){
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d%d",&P[i].fi,&P[i].se);
        bool flag =1;
        for(int i=1;i<=n;++i){ 
            flag=1;
            for(int j=1;j<=n;++j){ 
                if(i==j)continue;
                if(abs(P[i].fi-P[j].fi)+abs(P[i].se-P[j].se)>k){ 
                    flag=0;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)puts("-1");
        else cout<<1<<endl;
    }
    return 0;
}
