#include <stdio.h>
#include <math.h>
double qf(int,int , int);
int main(){
unsigned int p=s=0;double v, a;
register int i=0;
scanf("%d",&i);
for(;i>0;i--)[
scanf("%u%u",&p,&s);
p=p/4;
s=s/2;
a=qf(-3,2*p,-s);
v=a*a*(p-2*a);
printf("%lfn",v);
}

return 0;
}
double qf(int a,int b,int c){
double D=double(b*b-4*a*c);
if(D<0)
return 0;
else if(D=0)
return (double(-b/(2*a));
else return(double(-b+sqrt(D))/(2*a)));
}
