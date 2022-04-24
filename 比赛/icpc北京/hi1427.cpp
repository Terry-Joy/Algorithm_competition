#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef pair<int,char>P;
char mp[22][22];
int n,m;
P s[5];
bool cmp(P a,P b){
    if(a.fi==b.fi)return a.se<b.se;
    return a.fi>b.fi;
}
int main(){
    s[0].se='A';s[1].se='C';s[2].se='D';
    s[3].se='E';s[4].se='G';
    while(~scanf("%d%d",&n,&m)&&n&&m){
        for(int i=0;i<5;++i)s[i].fi=0;
        for(int i=1;i<=n;++i){
            scanf("%s",mp[i]+1);
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                for(int k=0;k<5;++k)
                    if(mp[i][j]==s[k].se)
                        s[k].fi++;
        sort(s,s+5,cmp);
        for(int i=0;i<5;++i){
            if(!s[i].fi)continue;
            cout<<s[i].se<<" "<<s[i].fi<<" ";
        }
        puts("");
    }
    return 0;
}