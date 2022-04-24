#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int nxt[maxn],len;
char s[maxn];
void getKmp(){
    for(int i=2,j=0;i<=len;++i){
        while(j&&s[i]!=s[j+1])j=nxt[j];
        if(s[i]==s[j+1])j++;
        nxt[i]=j;
    }
}
int main(){
    int T=0;
    while(~scanf("%d",&len)&&len){
        scanf("%s",s+1);
        getKmp();
        cout<<"Test case #"<<++T<<"\n";
        for(int i=2;i<=len;++i){
            if(i%(i-nxt[i])==0&&i!=(i-nxt[i])){
                cout<<i<<" "<<i/(i-nxt[i])<<"\n";
            }
        }
        puts("");
    } 
    return 0;
}