#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x, y, val; 
	bool operator<(const Node&a)const{
		return val>a.val;
	}
}a[1005];
int cnt;
int main(){
    int n, m, k,x;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
			cin>>x;
            if(x)
				a[++cnt] = Node{i,j,x};
        }
    }
	sort(a+1,a+1+cnt);
    int remain = k-a[1].x-1, ans = a[1].val;
    if(a[1].x*2+1 > k){
		 puts("0"); 
	}else{
    	for(int i = 2; i <= cnt; i++){
    	    if(remain >= abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)+(a[i].x)+1){
    	        ans += a[i].val;  
				remain -= abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)+1;
    	    }else 
				break;
    	}
    	cout<<ans;
	}
    return 0;
}