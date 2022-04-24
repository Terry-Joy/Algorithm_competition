#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
int n,k;
char s[2000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int len=0;
    for(int i=1;i<=k;++i){
        s[++len]=i+'a'-1;
        for(int j=1;j<=k-i;++j){
            s[++len]=i+'a'-1;
            s[++len]=i+j+'a'-1;
        }
    }
        for(int i=1;i<=n;++i){
            cout<<s[(i%len==0)?len:i%len];
        }
    return 0;
}