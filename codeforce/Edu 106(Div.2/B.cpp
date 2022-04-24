#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
char s[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>s;
        int len=strlen(s);
        bool f1=1,f2=1;
        for(int i=1;i<len;++i){
            if(s[i-1]=='1'&&s[i]=='1'){
                f1=0;
                for(int j=i+1;j<len-1;++j){
                    if(s[j]=='0'&&s[j+1]=='0')f2=0;
                }
            }
        }
        if(!f1&&!f2)cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
    return 0;
}