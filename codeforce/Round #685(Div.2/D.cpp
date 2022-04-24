#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
int t,n;
ll d,k;
int main(){
    ios::sync_with_stdio(false);cin.tie(0); 
    cin>>t;
    while(t--){ 
       cin>>d>>k;
       ll x=0;
       while((x+k)*(x+k)+(x+k)*(x+k)<=d*d)x+=k;
       if((x+k)*(x+k)+x*x<=d*d)cout<<"Ashish"<<endl;
       else cout<<"Utkarsh"<<endl; 
    }
    return 0;
}
