#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int t,n;
char s[maxn];
map<char,int>mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    mp['R']=1;mp['U']=1;
    mp['L']=mp['D']=-1;
    while(t--){ 
        int px,py;
        cin>>px>>py;
        cin>>s;
        bool f=0;
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<strlen(s);++i){
            if(s[i]=='U')a++;
            else if(s[i]=='D')b--;
            else if(s[i]=='L')c--;
            else d++;
        }
        if(px>=c&&px<=d&&py>=b&&py<=a)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
