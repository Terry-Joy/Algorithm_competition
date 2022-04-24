#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string,int> mp;
    string s;
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        mp[s]++;
    }
    cout<<"AC x "<<mp["AC"]<<'\n';
    cout<<"WA x "<<mp["WA"]<<'\n';
    cout<<"TLE x "<<mp["TLE"]<<'\n';
    cout<<"RE x "<<mp["RE"]<<'\n';

    return 0;
}