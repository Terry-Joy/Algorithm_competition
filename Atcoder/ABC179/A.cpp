#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    string a;
    cin>>a;
    if(a[a.size()-1]=='s')a+="es";
    else a+="s";
    cout<<a<<endl;
    return 0;
}