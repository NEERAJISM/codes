#include<iostream>
#include<stdio.h>
using namespace std;
int a[101][101],b[101][101],n,m;
int r[2][101],c[2][101];
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
	for(i=1;i<=m;i++)
	{
		x=0;
		for(j=1;j<=n;j++)
		{
			if(a[j][i]!=-1)
			x++;
			else if(a[j][i]==-1)
			{
				if(x>c[0][i])
				{
					c[0][i]=x;
					c[1][i]=j-1;
					x=0;
				}
			}
			if(j==n)
			{
				if(x>c[0][i])
				{
					c[0][i]=x;
					c[1][i]=j;
					x=0;
				}
			}
		}
	}
}
void spaces2()
{
	int i,j,x;
	for(i=1;i<=n;i++)
	{
		x=0;
		for(j=1;j<=m;j++)
		{
			if(b[i][j]!=-1)
			x++;
			else if(b[i][j]==-1)
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
	for(i=1;i<=m;i++)
	{
		x=0;
		for(j=1;j<=n;j++)
		{
			if(b[j][i]!=-1)
			x++;
			else if(b[j][i]==-1)
			{
				if(x>c[0][i])
				{
					c[0][i]=x;
					c[1][i]=j-1;
					x=0;
				}
			}
			if(j==n)
			{
				if(x>c[0][i])
				{
					c[0][i]=x;
					c[1][i]=j;
					x=0;
				}
			}
		}
	}
}
int maxr()
{
	int i,mr=0;
	for(i=1;i<=n;i++)
	if(mr<r[0][i])
	mr=r[0][i];
	return mr;
}
int maxc()
{
	int i,mc=0;
	for(i=1;i<=m;i++)
	if(mc<c[0][i])
	mc=c[0][i];
	return mc;
}
int maxvalue()
{
	int mr,mc;
	mr=maxr();
	mc=maxc();
	if(mr>mc)
	return 1;
	else 
	return 2;
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
int maxci()
{
	int i,mci=1,mc=0;
	for(i=1;i<=m;i++)
	if(mc<c[0][i])
	{
		mc=c[0][i];
		mci=i;
	}
	return mci;
}
int sumr()
{
	int i,s1=0;
	for(i=1;i<=n;i++)
	s1+=r[0][i];
	return s1;
}
int sumc()
{
	int i,s2=0;
	for(i=1;i<=m;i++)
	s2+=r[0][i];
	return s2;
}
int main()
{
	int k,i,j,e,d,mi,index;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;i++)
    {
    	scanf("%d%d",&e,&d);
    	a[e][d]=-1;
    	b[e][d]=-1;
    }
    int z=0,g,h,q;

 
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
        h=sumc(); // cout<<"h= "<<h<<endl;
    	
    /*	for(i=1;i<=n;i++)
    cout<<"row"<<r[0][i]<<" "<<r[1][i]<<endl;
    for(i=1;i<=m;i++)
    cout<<"column"<<c[0][i]<<" "<<c[1][i]<<endl;  */
    
        index=maxvalue();//cout<<"index= "<<index<<endl;
        if(index==1)
        {
    	    mi=maxri(); // cout<<"mi= "<<mi<<endl;
    	    for(j=0;j<r[0][mi];j++)
    	    a[mi][r[1][mi]-j]=-1;
        }
        else
        {
    	    mi=maxci(); // cout<<"mi= "<<mi<<endl;
    	    for(i=0;i<c[0][mi];i++)
    	    a[(c[1][mi]-i)][mi]=-1;
        }
        for(i=1;i<=n;i++)
        {
        	r[0][i]=0;r[1][i]=0;
        }
        for(i=1;i<=m;i++)
        {
        	c[0][i]=0;c[1][i]=0;
        }

    }
    while(g!=0&&h!=0);
    printf("%d\n",z);
    
    z=0;
    do
    {
      /*	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=m;j++)
    		cout<<a[i][j]<<"  ";
    		cout<<endl;
    	}*/
    	z++;
    	spaces2();
    	g=sumr(); // cout<<"g= "<<g<<endl;
        h=sumc(); // cout<<"h= "<<h<<endl;
    	
    /*	for(i=1;i<=n;i++)
    cout<<"row"<<r[0][i]<<" "<<r[1][i]<<endl;
    for(i=1;i<=m;i++)
    cout<<"column"<<c[0][i]<<" "<<c[1][i]<<endl;  */
    
        index=maxvalue();//cout<<"index= "<<index<<endl;
        if(index==1)
        {
    	    mi=maxri(); // cout<<"mi= "<<mi<<endl;
    	    for(j=0;j<r[0][mi];j++)
    	    b[mi][r[1][mi]-j]=-1;
        }
        else
        {
    	    mi=maxci(); // cout<<"mi= "<<mi<<endl;
    	    for(i=0;i<c[0][mi];i++)
    	    b[(c[1][mi]-i)][mi]=-1;
        }
        for(i=1;i<=n;i++)
        {
        	r[0][i]=0;r[1][i]=0;
        }
        for(i=1;i<=m;i++)
        {
        	c[0][i]=0;c[1][i]=0;
        }

    }
    while(g!=0&&h!=0);
     printf("%d\n",z); 
   return 0; 
}
