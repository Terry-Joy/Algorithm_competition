#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s="ww";
    string s1=s;
    string s2(s);
    cout<<s<<endl;
    s2+=s;
    cout<<s<<endl;
    return 0;
}

