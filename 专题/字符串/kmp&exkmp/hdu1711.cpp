#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int s1[maxn],s2[maxn];
int nxt[maxn],len1,len2,f[maxn],ans=0;
void getKmp(){
    nxt[1]=0;
    for(int i=2,j=0;i<=len2;++i){
        while(j&&s2[i]!=s2[j+1])j=nxt[j];
        if(s2[i]==s2[j+1])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=len1;++i){
        while(j&&(j==len2||s1[i]!=s2[j+1]))j=nxt[j];
        if(s1[i]==s2[j+1])j++;
        f[i]=j;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&len1,&len2);
        for(int i=1;i<=len1;++i)scanf("%d",&s1[i]);
        for(int i=1;i<=len2;++i)scanf("%d",&s2[i]);
        ans=-1;
        getKmp();
        for(int i=1;i<=len1;++i){
            if(f[i]==len2){
                ans=i-len2+1;break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}