#include<bits/stdc++.h>
using namespace std;

int h,w,k;
char g[10][10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>w>>k;
    for(int i=0;i<h;i++){
        cin>>g[i];
    }
    int ans=0;
    for(int s=0;s<1<<h+w;s++){
        int c=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                c+=!(s>>i&1)&&!(s>>h>>j&1)&&g[i][j]=='#';
            }
        }
        ans+=c==k;
    }
    cout<<ans<<endl;

    return 0;
}