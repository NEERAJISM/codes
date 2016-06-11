#include <iostream>
#include <cstdio>
using namespace std;
void mergesort(int a[],int l,int m,int h)
{
	int i =l;
	int b[h-l+1];
	int j = m+1;
	int k = 0;
	int n1 = m-l+1;
	int n2 = h-m;

	while(i <= m && j <= h)
	{
		if(a[i] > a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}

	while(i<=m)
	{
		b[k] = a[i];
		i++;
		k++;
	}

	while(j<=h)
	{
		b[k] = a[j];
		j++;
		k++;
	}

	for (int i = 0; i < k; ++i)
	{
		a[l] = b[i];
		l++;
	}
}


void merge(int a[],int low,int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		merge(a,low,mid);
		merge(a,mid+1,high);
		mergesort(a,low,mid,high);
	}

}

int main()
{
	int t,n,a[100000],flag,i,count = 2;
	scanf("%d",&t);

	while(t--)
	{
	    count = 2;
		flag = 0;
		scanf("%d",&n);

        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&a[i]);
            if(a[i]<2)
                flag = 1;
        }

        if (flag == 1)
            printf("-1\n");
        else
        {
            merge(a,0,n-1);

            //for(int i= 0;i<n;i++)
                //cout<<a[i]<<" ";
            //cout<<endl;

            for (int i = 0; i < n-1; ++i)
            {
                count += a[i];
            }
            printf("%d\n",count );
        }
    }
	return 0;
}
