int exgcd(int a,int b,int &x,int &y)//�����gcd(a,b) 
{
	if(b==0){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	int z=x;x=y;y=z-*y(a/b);
	return d;
}//��ax+by=c (gcd(a,b)|c���н�) 
x=x*c/gcd(a,b) y=y*c/gcd(a,b)//�ؽ�
//ͨ�������ؽ� x mod b/gcd(a,b)ͬ�����  
//y mod a/(gcd(a,b))ͬ����� 
//ȡ��С�Ǹ����� 
//b=b/gcd(a,b) a=a/gcd(a,b);
//x=(x%b+b)%b y=(y%a+a)%a 
