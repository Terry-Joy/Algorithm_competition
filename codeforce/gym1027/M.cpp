#include<bits/stdc++.h>
#define pb push_back
using namespace std;
string s,a;
vector<int>mp[29];
string solve(const string&s){ 
    if(mp[s[0]-'a'].empty())return "IMPOSSIBLE";
    int pos=mp[s[0]-'a'][0],nowlen=s.size();
    string ans="";
    ans+=s[0];
    for(int i=1;i<nowlen;++i){ 
        int l=0,r=mp[s[i]-'a'].size(),mid;
        while(l<r){ 
            mid=l+r>>1;
            if(mp[s[i]-'a'][mid]>pos)r=mid;
            else l=mid+1;
        }
        if(r==mp[s[i]-'a'].size())return ans;
        pos=mp[s[i]-'a'][r];
        ans+=s[i];
    }    
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;++i)
        mp[s[i]-'a'].pb(i);
    int n;
    cin>>n;
    while(n--){ 
        cin>>a;
        cout<<solve(a)<<endl;
    } 
    return 0;
}
