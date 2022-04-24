int exgcd(int a,int b,int &x,int &y)//求的是gcd(a,b) 
{
	if(b==0){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	int z=x;x=y;y=z-*y(a/b);
	return d;
}//解ax+by=c (gcd(a,b)|c才有解) 
x=x*c/gcd(a,b) y=y*c/gcd(a,b)//特解
//通解是与特解 x mod b/gcd(a,b)同余的数  
//y mod a/(gcd(a,b))同余的数 
//取最小非负整数 
//b=b/gcd(a,b) a=a/gcd(a,b);
//x=(x%b+b)%b y=(y%a+a)%a 
