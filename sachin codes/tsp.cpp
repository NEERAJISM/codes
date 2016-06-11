#include<iostream>
#include<stdlib.h>

using namespace std;
int global = 11;
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
  global = global * 13 % 99998953;
  srand(global);
	x=rand()%n + 1;
global = global * 13 % 99998953;
  srand(global);
	y=rand()%n + 1;
	t=b[x];
	b[x]=b[y];
	b[y]=t;
	return 0;
}


float m_cost(int a[20][20],int n)
{  
     float s1 = 0;
	for(int i=1;i<=n;i++)
	   {
	   	        //s1=0;
	   	      int m=a[i][1];
	   	  for(int j=1;j<=n;j++)
	   	     {
	   	     	if(a[i][j]<m)
	   	     	m=a[i][j];
	   	     }
	   	  s1+=m;   
	   }
	   //cout<<"hello"<<s1;
 return s1;	   
}


float quality(float s2,int n,int a[20][20])
{ 
    float s1=m_cost(a,n);
  //  printf("hi");
    float q;
    q=((s2-s1)/s1)*100;
    //cout<<"val q"<<q;
    return q;

}


int main()
{    
	int n,a[20][20],b[20],i,j;
	float s1,s2,q;
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
	   
	   
	do{
		
	    crossover(b,n);
	    
	    s2=cost(b,a,n);
	    
	    q=quality(s2,n,a);
	    
	    if(q>22)
	    { 
	    cout<<"best path is   "<<endl;
		for(i=1;i<=n;i++)
	    cout<<b[i]<<"---";
	    for(i = 1; i < 99999999; i++ ) ;//delay loop
	    }
	} 
	while(q<90);
	  
return 0;	      
}
