#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   cout<<s.substr(0,n)<<(s.size()>n?"...":"");
   return 0; 
}
