#include<iostream>
#include<stdio.h>
using namespace std;
int a[101][101],n,m;
int r[2][101],A[10000],B[10000];
void spaces()
{
	int i,j,x;
	for(i=1;i<=n;i++)
	{
		x=0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]!=-1)
			x++;
			else if(a[i][j]==-1)
			{
				if(x>r[0][i])
				{
					r[0][i]=x;
					r[1][i]=j-1;
					x=0;
				}
			}
			if(j==m)
			{
				if(x>r[0][i])
				{
					r[0][i]=x;
					r[1][i]=j;
					x=0;
				}
			}
		}
	}

}
int maxri()
{
	int i,mri=1,mr=0;
	for(i=1;i<=n;i++)
	if(mr<r[0][i])
	{
		mr=r[0][i];
		mri=i;
	}
	return mri;
}
int sumr()
{
	int i,s1=0;
	for(i=1;i<=n;i++)
	s1+=r[0][i];
	return s1;
}
int main()
{
	int k,i,j,e,d,mi,index;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;i++)
    {
    	scanf("%d%d",&e,&d);
    	a[e][d]=-1;
    }
    int z=0,g,I=1;

    do
    {
      /*	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=m;j++)
    		cout<<a[i][j]<<"  ";
    		cout<<endl;
    	}*/
    	z++;
    	spaces();
    	g=sumr(); // cout<<"g= "<<g<<endl;
    	
    /*	for(i=1;i<=n;i++)
    cout<<"row"<<r[0][i]<<" "<<r[1][i]<<endl;
    for(i=1;i<=m;i++)
    cout<<"column"<<c[0][i]<<" "<<c[1][i]<<endl;  */
    
    	    mi=maxri();// cout<<"mi= "<<mi<<endl;
    	    A[I]=mi;B[I]=r[1][mi];I++;
    	    for(j=0;j<r[0][mi];j++)
    	    a[mi][r[1][mi]-j]=-1;
        for(i=1;i<=n;i++)
        {
        	r[0][i]=0;r[1][i]=0;
        }

    }
    while(g!=0);
    z--;  
    printf("%d\n",z);
  
    for(i=1;i<=z;i++)
    printf("%d %d 0\n",A[i],B[i]);
    return 0;
}
