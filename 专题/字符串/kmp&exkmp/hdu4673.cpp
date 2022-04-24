#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int t,nxt[maxn],len;
char s[maxn];
void getKmp(){
    nxt[1]=0;
    for(int i=2,j=0;i<=len;++i){
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
bool check(int x){
    int l=x+x,r=len-x;
    for(int i=l;i<=r;++i){
        if(nxt[i]>=x)return 1;
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        len=strlen(s+1);
        getKmp();
        int l=-1,r=nxt[len];
        while(r*3>len)r=nxt[r];
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        cout<<l<<"\n";
    }
    return 0;
}