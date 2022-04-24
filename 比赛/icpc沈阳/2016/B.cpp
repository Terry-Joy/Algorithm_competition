#include<bits/stdc++.h>

using namespace std;
char s[12];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){ 
        int ans=0;
        cin>>s;
        int len=strlen(s);
        for(int i=0;i<len;++i){ 
            if(s[i]=='H')ans+=1;
            else if(s[i]=='O')ans+=16;
            else if(s[i]=='C')ans+=12;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
