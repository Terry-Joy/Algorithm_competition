#include<bits/stdc++.h>
using namespace std;
int t,n,m;
string s1,s2,s3;
int main(){
    cin>>t;
    int T=0;
    while(t--){ 
        cin>>n>>m;
        cin>>s1>>s2>>s3;
        int del=s2[0]-s1[0];
        cout<<"Case #"<<++T<<": ";
        for(int i=0;i<m;++i)
            cout<<char(((s3[i]-'A'-del+26)%26)+'A');
        cout<<"\n";
    }
    return 0;
}
