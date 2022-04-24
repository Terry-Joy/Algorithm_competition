#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
char s[210];
int main(){
    cin>>t;
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        sort(s+1,s+1+n);
        for(int i=1;i<=n;++i)cout<<s[i];
        cout<<"\n";    
    } 
    return 0;
}
