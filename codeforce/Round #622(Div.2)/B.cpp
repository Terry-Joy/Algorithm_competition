#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            cout << 1 <<" "<<1<< endl;
        else{
            cout << max(1, min(a, b + c - a + 1)) << " ";
        if (b + c - 1 >a)
            cout << a << endl;
        else
            cout << min(a, a - (abs(a - b + 1 - c))) << endl;
        }
    }
}

