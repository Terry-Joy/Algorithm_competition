import math
n=int(input())
x=n%3
y=n//3
ans=n*(n-1)//2-2*y*(y-1)-2*y*x-y-(x==2)
print('%d'%ans)