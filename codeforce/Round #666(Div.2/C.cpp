#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
       scanf("%lld",&a[i]);
   if(n==1){
       cout<<1<<" "<<1<<endl;
       cout<<-1*a[1]<<endl;
       for(int i=1;i<=2;++i){ 
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
       }
       return 0;
   }
   cout<<1<<" "<<1<<endl;
   cout<<a[1]*(n-1)<<endl;
   cout<<2<<" "<<n<<endl;
   for(int i=2;i<=n;++i)
       cout<<1ll*a[i]*(n-1)<<" ";
   cout<<endl;
   cout<<1<<" "<<n<<endl;
   for(int i=1;i<=n;++i)
      cout<<-1ll*n*a[i]<<" ";
   return 0; 
}
