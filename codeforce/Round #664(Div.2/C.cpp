#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,a[205],b[205];
bool check(int x){ 
    bool flag=0;
    for(int i=1;i<=n;++i)
    {
       flag=0; 
       for(int j=1;j<=m;++j)
       {
          if((x|(a[i]&b[j]))==x)
             flag=1;
          if(flag)break;
       } 
       if(!flag)return 0;
    }
    return 1;
}
int main(){ 
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int j=1;j<=m;++j)
        cin>>b[j];
    for(int i=0;i<(1<<9);++i){ 
        if(check(i))
        { 
            cout<<i<<endl;
    return 0;
        }
    }
}
