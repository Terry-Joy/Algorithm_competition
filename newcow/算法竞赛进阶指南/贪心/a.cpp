#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int a[4][5]={ {1,2,3,4,0},{5,6,7,8,0 },{9,10,11,12,0 },{13,14,15,16,0 }};
    for (auto p=a[0];p!=a[1];p++){
		cout<<p<<' '<<*p<<endl;
	}
	// vector<vector<int>>v(a[0],a[1]);
    // cout<<a[0]<<"\n";
    // cout<<v.size()<<"\n";
    // for(int j=0;j<v.size();++j){ 
    //     for(int i=0;i<v[j].size();++i)
    //         cout<<v[j][i]<<" ";
    //     cout<<endl;
    // }
    // return 0;
}
