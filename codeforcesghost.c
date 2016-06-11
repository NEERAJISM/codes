#include<stdio.h>
int main()
{
  int m,count=0,i,t,r,g[300],light;
  
  scanf("%d%d%d",&m,&t,&r);
  
  for(i=0;i<m;i++)
    scanf("%d",&g[i]);
  
  if(g[0]>r||t<r)
  {
    printf("-1");
    
  }
  else
  {
      count=r;
      i=0;
      light = g[0]+t;
    while(1)
    {
      while(g[i]<=light&&i<m)
	i++;
      if(i>=m)
      {
	printf("%d",count);
	return 0;
      }
      count=count+(g[i]-light);
      light=g[i]+t;
    }
  }
}   
