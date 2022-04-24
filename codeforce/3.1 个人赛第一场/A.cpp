
#include<bits/stdc++.h>
using namespace std;
int main(){
    int s, g;
 
    cin >> s >> g;
    if(s % g != 0 || s <= g)cout << -1 << endl;
    else{
       cout<<g<<" "<<s-g<<endl;
    }
    return 0;
}

