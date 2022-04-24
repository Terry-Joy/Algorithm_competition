#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
map<char,string>mp;
int main()
{
   mp['2']=mp['4']=mp['5']=mp['7']=mp['9']="hon";
   mp['0']=mp['1']=mp['6']=mp['8']=mp['8']="pon";
   mp['3']="bon";
   string s;
   cin>>s;
   cout<<mp[s.back()];
   return 0; 
}
