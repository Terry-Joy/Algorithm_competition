#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
#define LL long long
using namespace std;
const int N=2005;
string s[10]={"1110111","0010010","1011101","1011011",
"0111010","1101011","1101111","1010010","1111111","1111011"};
int n;          //用数组s来存0-9
string a[N];    //用a存给出的数
bool flag=0,st[N][N];  //flag判断是否已经有解,用st[]存不合法的情况,避免重复计算
int ans[N];     //用ans来存答案
void dfs(int pos,int k)    //pos表示枚举到了第几个数，k是剩余修改次数
{
	if(flag||k<0) return;  //如果有解或修改次数为负则结束
	if(pos==n)
	{   //如果枚举完n个数且剩余修改次数正好为0，则输出答案并记录
		if(k==0)
		{
			flag=true;
			for(int i=0;i<n;i++) cout<<ans[i];
			cout<<endl;
			return;
		}
		else return;
	}
    if(st[pos][k]) return;  //已经算出了该状态不合法，返回
	for(int i=9;i>=0;i--)   //因为要求最大值，所以从大到小枚举
	{
		int cnt=0;       //记录a[pos]修改成数i需要的次数
		bool state=false;//记录a[pos]能否修改成数i
		for(int j=0;j<7;j++)  //枚举每一位
		if(a[pos][j]=='0'&&s[i][j]=='1') cnt++; //修改需要打开该灯管则可以修改
		else if(a[pos][j]=='1'&&s[i][j]=='0') 
		{   //修改需要关闭该灯管，则不可修改，所以，a[pos]不能改为数i
			state=true;
			break;
		}
		
		if(state) continue;
		ans[pos]=i;        //可以修改则用ans记录
		dfs(pos+1,k-cnt);  //继续枚举下一个数
	}
	if(!flag) st[pos][k]=true;  //如果枚举完毕还没有得到解，说明该情况不
}                               //合法，用st数组记录
int main()
{
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    dfs(0,k);
    
    if(!flag) puts("-1");   //如果没有解输出-1
    return 0;
}
