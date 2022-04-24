#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a,b,x,y;
int main(){
    cin>>a>>b>>x>>y;
    if(a>b)
        cout<<min(2*x,y)*max(0,abs(a-b)-1)+x;
    else
        cout<<min(2*x,y)*max(0,abs(a-b))+x;
	return 0;
}

