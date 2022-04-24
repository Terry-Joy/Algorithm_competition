#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll k,x;
int solve(int x){
   if(x<=9&&x>=1)return x;
   int i=x,ans=0;
   while(i){
      ans+=i%10;
      i/=10;
   }
   return solve(ans);
}
int cnt[200];
int main(){
   int n;
   scanf("%d",&n);
   /*for(int i=1;i<=100;++i){
      cnt[solve(i)]++;
      cout<<i<<" "<<solve(i)<<" "<<cnt[solve(i)]<<'\n';
   }*/
   while(n--){
      ll k;int x;
      cin>>k>>x;
      cout<<9*(k-1)+x<<"\n";
   }
   return 0; 
}
