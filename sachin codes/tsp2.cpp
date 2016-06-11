#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

float cost(int b[20],int a[20][20],int n)
{  float s2=0;

for(int i=1;i<=n-1;i++)
    {
    //printf("s2 = %f %d %d\n",s2,b[i],b[i+1]);
     s2=s2+a[b[i]][b[i+1]];
    }
    
     s2+=a[b[n]][b[1]];
     return s2;
}

int crossover(int b[20],int n)
{   
  int x,y,t;
  
  srand(time(NULL));
	x=rand()%n + 1;cout<<x;
srand((x*100000)%99876);

	y=rand()%n + 1;cout<<y;
	t=b[x];
	b[x]=b[y];
	b[y]=t;
	return 0;
}




int main()
{    
	int n,a[20][20],b[20],c[20],i,j;
	float s1,s2,q,mcost;
	cout<<"enter the no of cities";
	cin>>n;
	cout<<"enter the distance b/w cities in pattern... 1-1,1-2,1-3,2-1,2-2";
	for(i=1;i<=n;i++)
	   {
	   	   for(j=1;j<=n;j++)
	   	      cin>>a[i][j];
	   }
	   
	   
	for(i=1;i<=n;i++)
	   b[i]=i;
	   
	   
	for(j=1;j<=10;j++) //no of generations
	{
		    crossover(b,n);
	    
	    s2=cost(b,a,n);
	    
	  if(j==1)
	  {
	    
	    mcost=s2;
	    for(i=1;i<=n;i++)
	    {
	    	c[i]=b[i];
	    }
      } 
      if(s2<mcost)
      {
      	mcost=s2;
      	for(i=1;i<=n;i++)
      	{
      		c[i]=b[i];
      	}
      }
	   
	}
	cout<<"least distance is "<<mcost<<"\n";
	cout<<"best path is ";
	for(i=1;i<=n;i++)
	cout<<c[i]<<"\n";
	  
return 0;	      
}
