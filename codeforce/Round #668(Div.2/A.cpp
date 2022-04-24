#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;
typedef long long ll;
int a[105];
int main(){
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=n;i>=2;--i)
            cout<<a[i]<<" ";
        cout<<a[1]<<endl;
    }
    return 0;
}
