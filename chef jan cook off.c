#include<stdio.h>
int a[1000],a1[1000];
void merge(int x1,int r1,int y1)
{
	int i,k,j,n;
	i=x1;
	j=r1+1;
	k=0;
	while(i<=r1&&j<=y1)
	{
		if(a[i]<a[j])
		{
			a1[k]=a[i];
			i++;
			k++;
		}
		else
		{
			a1[k]=a[j];
			j++;
			k++;
		}
	}

	while(i<=r1)
	{
		a1[k]=a[i];
		k++;
		i++;
	}

	while(j<=y1)
	{
		a1[k]=a[j];
		k++;
		j++;
	}

	for(n=0;n<k;n++)
		a[x1+n]=a1[n];
}

void mergesort(int x,int y)
{
	if(x<y)
	{
		int r = (x+y)/2;
		mergesort(x,r);
		mergesort(r+1,y);
		merge(x,r,y);
	}
}

int main()
{
	int n,i,t,count;
	scanf("%d",&t);
	while(t-->0)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        mergesort(0,n-1);
        count=0;
        for(i=n-1;i>=0;i-=4)
        {
            count=count+a[i];
            if(i-1>=0)
                count=count+a[i-1];
        }

        printf("%d\n",count);
    }
return 0;
}
